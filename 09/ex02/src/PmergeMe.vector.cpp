#include "../includes/PmergeMe.hpp"

void PmergeMe::runVector(int argc, char **argv) {
	clock_t start = clock(); 
	fillMainVectorList(argc, argv);
	std::cout << "Before: ";
	printVector(_vectorList);

	std::vector<std::vector<int> > mainSubLists;
	std::vector<int> pendingList;

	divideVector(_vectorList, mainSubLists);
	separateVectorValues(_vectorList, mainSubLists, pendingList);
	insertingIntoMainVector(_vectorList, pendingList);
	std::cout << "After: ";
	printVector(_vectorList);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << _vectorList.size()
	<< " elements with std::vector : " << std::fixed << std::setprecision(6) <<  duration << " s" << std::endl;
}

void	PmergeMe::fillMainVectorList(int argc, char **argv) {
	int number;

	for (int i = 1; i < argc; i++) {
		number = std::atoi(argv[i]);
		_vectorList.push_back(number);
	}
}

void	PmergeMe::divideVector(std::vector<int>& mainList, std::vector<std::vector<int> >& mainSublists) {
	while (mainList.size() > 1) {
		std::vector<int> pair;
		pair.push_back(mainList.front());
		mainList.erase(mainList.begin());

		pair.push_back(mainList.front());
		mainList.erase(mainList.begin());

		mainSublists.push_back(pair);
	}

	if (!mainList.empty()) {
		std::vector<int> lastElem;
		lastElem.push_back(mainList.front());
		mainSublists.push_back(lastElem);
		mainList.erase(mainList.begin());
	}
}

void	PmergeMe::separateVectorValues(std::vector<int>& mainList, std::vector<std::vector<int> >& mainSublists, std::vector<int>& pendingList) {
	int first, second;

	for (size_t i = 0; i < mainSublists.size(); i++) {
		if (mainSublists[i].size() == 1) {
			pendingList.push_back(mainSublists[i][0]);
			std::sort(mainList.begin(), mainList.end());
			return;
		}

		first = mainSublists[i][0];
		second = mainSublists[i][1];

		if (first > second) {
			mainList.push_back(first);
			pendingList.push_back(second);
		} else {
			mainList.push_back(second);
			pendingList.push_back(first);
		}
	}

	std::sort(mainList.begin(), mainList.end());
}

void	PmergeMe::insertingIntoMainVector(std::vector<int>& mainList, std::vector<int>& pendingList) {
	if (pendingList.empty()) {
		return;
	}

	int pendingListSize = pendingList.size();
	std::vector<bool> inserted(pendingListSize, false);

	int i = 0;
	while (std::find(inserted.begin(), inserted.end(), false) != inserted.end()) {
		int jacobIndex = jacobsthalSequency(i);

		if (jacobIndex >= pendingListSize) {
			checkPreviousAndInsert(mainList, jacobIndex, inserted, pendingList);
			break;
		}

		if (!inserted[jacobIndex] && pendingList[jacobIndex]) {
			findMatchingAndInsert(mainList, pendingList[jacobIndex]);
			inserted[jacobIndex] = true;
			checkPreviousAndInsert(mainList, jacobIndex, inserted, pendingList);
		}
		i++;
	}
}

void	PmergeMe::findMatchingAndInsert(std::vector<int>& mainList, int value) {
	for (size_t i = 0; i < mainList.size(); i++) {
		if (mainList[i] > value) {
			mainList.insert(mainList.begin() + i, value);
			return;
		}
	}
	mainList.push_back(value);
}

void	PmergeMe::checkPreviousAndInsert(std::vector<int>& mainList, int jacobIndex, std::vector<bool>& inserted, std::vector<int>& pendingList) {
	int maxSize = pendingList.size() - 1;
	
	if (jacobIndex > maxSize) {
		jacobIndex = maxSize;
	}
	while (jacobIndex >= 0) {
		if (!inserted[jacobIndex] && pendingList[jacobIndex]) {
			findMatchingAndInsert(mainList, pendingList[jacobIndex]);
			inserted[jacobIndex] = true;
		}
		jacobIndex--;
	}
}