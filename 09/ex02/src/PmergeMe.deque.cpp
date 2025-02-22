#include "../includes/PmergeMe.hpp"

void PmergeMe::runDeque(int argc, char **argv) {
	clock_t start = clock(); 
	fillMainDequeList(argc, argv);

	std::deque<std::deque<int> > mainSubLists;
	std::deque<int> pendingList;

	divideDeque(_dequeList, mainSubLists);
	separateDequeValues(_dequeList, mainSubLists, pendingList);
	insertingIntoMainDeque(_dequeList, pendingList);
	clock_t end = clock();
	double duration = static_cast<double>(end - start)/ CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << _dequeList.size()
	<< " elements with std::deque : " << std::fixed << std::setprecision(6) << duration << " s" << std::endl;
}

void PmergeMe::fillMainDequeList(int argc, char **argv) {
	int number;

	for (int i = 1; i < argc; i++) {
		number = std::atoi(argv[i]);
		_dequeList.push_back(number);
	}
}

void PmergeMe::divideDeque(std::deque<int>& mainList, std::deque<std::deque<int> >& mainSublists) {
    while (mainList.size() > 1) {
        std::deque<int> pair;
        pair.push_back(mainList.front());
        mainList.pop_front();

        pair.push_back(mainList.front());
        mainList.pop_front();

        mainSublists.push_back(pair);
    }

    if (!mainList.empty()) {
        std::deque<int> lastElem;
        lastElem.push_back(mainList.front());
        mainSublists.push_back(lastElem);
        mainList.pop_front();
    }
}

void PmergeMe::separateDequeValues(std::deque<int>& mainList, std::deque<std::deque<int> >& mainSublists, std::deque<int>& pendingList) {
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

void PmergeMe::insertingIntoMainDeque(std::deque<int>& mainList, std::deque<int>& pendingList) {
    if (pendingList.empty()) {
        return;
    }

    int pendingListSize = pendingList.size();
    std::deque<bool> inserted(pendingListSize, false);

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

void PmergeMe::findMatchingAndInsert(std::deque<int>& mainList, int value) {
    for (size_t i = 0; i < mainList.size(); i++) {
        if (mainList[i] > value) {
            mainList.insert(mainList.begin() + i, value);
            return;
        }
    }
    mainList.push_back(value);
}

void PmergeMe::checkPreviousAndInsert(std::deque<int>& mainList, int jacobIndex, std::deque<bool>& inserted, std::deque<int>& pendingList) {
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
