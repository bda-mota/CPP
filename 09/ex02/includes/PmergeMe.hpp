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

	// deque methods
	void	runDeque(int argc, char **argv);
	void	fillMainDequeList(int argc, char **argv);
	void	divideDeque(std::deque<int>& mainList, std::deque<std::deque<int> >& pendingList);
	void	separateDequeValues(std::deque<int>& mainList, std::deque<std::deque<int> >& pendingList, std::deque<int>& sublist);
	void	insertingIntoMainDeque(std::deque<int>& mainList, std::deque<int>& sublist);
	void	findMatchingAndInsert(std::deque<int>& mainList, int value);
	void	checkPreviousAndInsert(std::deque<int>& mainList, int jacobIndex, std::deque<bool>& inserted, std::deque<int>& pendingList);
};

template <typename Container>
	static bool isSorted(const Container& c) {
		return std::adjacent_find(c.begin(), c.end(), std::greater<int>()) == c.end();
}

template <typename T>
void printContainers(const T& container)
{
	int	count = 0;

	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (count == 5) {
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
		count++;
	}
	std::cout << std::endl;
}

template <typename T>
void printAllContainers(const T& container)
{
	std::cout << "---------------------------------------------------------------------" << std::endl;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
}


#endif