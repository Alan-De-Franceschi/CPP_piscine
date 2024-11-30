#include <iostream>
#include <ctime>
#include <string>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";created" 
		<< std::endl;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	return ;
}

Account::Account(void) 
{
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"
		<< std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	std::time_t time;
	
	std::time(&time);
	char timeStr[20];
	std::strftime(timeStr, sizeof(timeStr), "[%Y%m%d_%H%M%S] ", std::gmtime(&time));
	std::cout << timeStr << std::flush;
	return ;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 
		<< "accounts:" << _nbAccounts 
		<< ";total:" << _totalAmount 
		<< ";deposits:" << _totalNbDeposits 
		<< ";withdrawals:" << _totalNbWithdrawals 
		<< std::endl;
	return ;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return ;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit
		<< std::flush;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout 
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:"
		<< std::flush;
	if (withdrawal <= this->_amount)
	{
		std::cout << withdrawal << std::flush;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout 
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	return (true);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
