#include <iostream>
#include "../includes/Account.hpp"

# define BLUE	"\033[34;1m"
# define RESET	"\033[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << RESET << ";amount:" << BLUE << _amount << RESET << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << RESET << ";amount:" << BLUE << _amount << RESET << ";closed" << std::endl;
}

int	Account::getNbAccounts() { return _nbAccounts; }
int	Account::getTotalAmount() { return _totalAmount; }
int	Account::getNbDeposits() { return _totalNbDeposits; }
int	Account::getNbWithdrawals() { return _totalNbWithdrawals; }
void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << BLUE << getNbAccounts() << RESET << ";total:" << BLUE << getTotalAmount() << RESET <<
	";deposits:" << BLUE << getNbDeposits() << RESET << ";withdrawals:" << BLUE << getNbWithdrawals() << RESET << std::endl;
}

void	Account::_displayTimestamp() {
	std::cout << "[19920104_091532] ";
}

void	Account::makeDeposit(int deposit) {
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << RESET << ";p_amount:" << BLUE << p_amount << RESET << ";deposit:" << BLUE << deposit
	<< RESET << ";amount:" << BLUE << _amount << RESET << ";nb_deposits:" << BLUE << _nbDeposits << RESET << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount;

	p_amount = _amount;
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << BLUE << _accountIndex << RESET << ";p_amount:" << BLUE << _amount << RESET << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << RESET << ";p_amount:" << BLUE << p_amount << RESET << ";withdrawal:" << BLUE << withdrawal << RESET
	<< ";amount" << BLUE << _amount << RESET << ";nb_withdrawals:" << BLUE << _nbWithdrawals << RESET << std::endl;
	return true;
}

int	Account::checkAmount() const { return _amount; }

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:"  << BLUE << _accountIndex << RESET << ";amount:" << BLUE << _amount << RESET << ";deposits:" << BLUE << _nbDeposits << RESET << ";withdrawals:" << BLUE << _nbWithdrawals  << RESET << std::endl;
}
