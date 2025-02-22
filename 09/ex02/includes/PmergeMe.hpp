#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <exception>
# include <cstdlib>
# include <algorithm>
# include <iomanip>

class PmergeMe {
private:
	std::vector<int> _vectorList;
	std::deque<int> _dequeList;

public:
	PmergeMe();
	PmergeMe(PmergeMe const & other);
	PmergeMe & operator=(PmergeMe const & other);
	~PmergeMe();

	// getters
	std::vector<int> getVectorMainList() const;
	std::deque<int> getDequeMainList() const;

	void	isValidInput(int argc, char **argv);
	void	isValidNumber(std::string slice);
	int		jacobsthalSequency(int n);
	
	// vector methods
	void	runVector(int argc, char **argv);
	void	fillMainVectorList(int argc, char **argv);
	void	divideVector(std::vector<int>& mainList, std::vector<std::vector<int> >& pendingList);
	void	separateVectorValues(std::vector<int>& mainList, std::vector<std::vector<int> >& pendingList, std::vector<int>& sublist);
	void	insertingIntoMainVector(std::vector<int>& mainList, std::vector<int>& sublist);
	void	findMatchingAndInsert(std::vector<int>& mainList, int value);
	void	checkPreviousAndInsert(std::vector<int>& mainList, int jacobIndex, std::vector<bool>& inserted, std::vector<int>& pendingList);
	void	printVector(const std::vector<int> &vec);

	// deque methods
	void	runDeque(int argc, char **argv);
	void	fillMainDequeList(int argc, char **argv);
	void	divideDeque(std::deque<int>& mainList, std::deque<std::deque<int> >& pendingList);
	void	separateDequeValues(std::deque<int>& mainList, std::deque<std::deque<int> >& pendingList, std::deque<int>& sublist);
	void	insertingIntoMainDeque(std::deque<int>& mainList, std::deque<int>& sublist);
	void	findMatchingAndInsert(std::deque<int>& mainList, int value);
	void	checkPreviousAndInsert(std::deque<int>& mainList, int jacobIndex, std::deque<bool>& inserted, std::deque<int>& pendingList);
	void	printDeque(const std::deque<int> &vec);
};

#endif