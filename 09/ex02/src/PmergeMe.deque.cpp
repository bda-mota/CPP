#include "../includes/PmergeMe.hpp"

void PmergeMe::runDeque(int argc, char **argv) {
	try {
		fillMainDequeList(argc, argv);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::deque<std::deque<int> > mainSubLists;
	std::deque<int> sublist;

	divideDeque(_dequeList, mainSubLists);
	for (size_t i = 0; i < mainSubLists.size(); i++) {
		printDeque(mainSubLists[i]);
	}
	separateDequeValues(_dequeList, mainSubLists, sublist);
	std::cout << "sublist: " << std::endl;
	printDeque(sublist);
	// Inserção de acordo com Jacobsthal
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

void PmergeMe::separateDequeValues(std::deque<int>& mainList, std::deque<std::deque<int> >& mainSublists, std::deque<int>& sublist) {
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

void PmergeMe::printDeque(const std::deque<int>& dq) {
	for (size_t i = 0; i < dq.size(); i++) {
		std::cout << dq[i] << " ";
	}
	std::cout << std::endl;
}