#include "../includes/PmergeMe.hpp"

void PmergeMe::runVector(int argc, char **argv) {
	try {
		isValidInput(argc, argv);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	fillMainVectorList(argc, argv);

	std::vector<std::vector<int> > mainSubLists;
	std::vector<int> sublist;

	divideVector(_vectorList, mainSubLists);
	for (size_t i = 0; i < mainSubLists.size(); i++) {
		printVector(mainSubLists[i]);
	}
	separateVectorValues(_vectorList, mainSubLists, sublist);
	std::cout << "sublist: " << std::endl;
	printVector(sublist);
	// inserção de acordo com Jacobsthal
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

void	PmergeMe::separateVectorValues(std::vector<int>& mainList, std::vector<std::vector<int> >& mainSublists, std::vector<int>& sublist) {
	int first, second;

	for (size_t i = 0; i < mainSublists.size(); i++) {
		if (mainSublists[i].size() == 1) {
			sublist.push_back(mainSublists[i][0]);
			return;
		}

		first = mainSublists[i][0];
		second = mainSublists[i][1];

		if (first > second) {
			mainList.push_back(first);
			sublist.push_back(second);
		} else {
			mainList.push_back(second);
			sublist.push_back(first);
		}
	}

	 std::sort(mainList.begin(), mainList.end());
}
