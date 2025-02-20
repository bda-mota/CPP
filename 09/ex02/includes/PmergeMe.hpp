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
	
	// vector methods
	void	runVector(int argc, char **argv);
	void	fillMainVectorList(int argc, char **argv);
	void	divideVector(std::vector<int>& mainList, std::vector<std::vector<int> >& sublists);
	void	separateVectorValues(std::vector<int>& mainList, std::vector<std::vector<int> >& sublists, std::vector<int>& sublist);
	void	printVector(const std::vector<int> &vec); // apagar depois

	// deque methods
	void	runDeque(int argc, char **argv);
	void	fillMainDequeList(int argc, char **argv);
	void	divideDeque(std::deque<int>& mainList, std::deque<std::deque<int> >& sublists);
	void	separateDequeValues(std::deque<int>& mainList, std::deque<std::deque<int> >& sublists, std::deque<int>& sublist);
	void	printDeque(const std::deque<int> &vec); // apagar depois
};

#endif