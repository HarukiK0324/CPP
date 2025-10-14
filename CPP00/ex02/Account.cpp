#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:\033[34m" << Account::getNbAccounts()
			  << "\033[0m;total:\033[34m" << Account::getTotalAmount()
			  << "\033[0m;deposits:\033[34m" << Account::getNbDeposits()
			  << "\033[0m;withdrawals:\033[34m" << Account::getNbWithdrawals()
			  << "\033[0m" << std::endl;
}

Account::Account( int initial_deposit )
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:\033[34m" << _accountIndex
			  << "\033[0m;amount:\033[34m" << _amount
			  << "\033[0m;created" << std::endl;
}
Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:\033[34m" << _accountIndex
			  << "\033[0m;amount:\033[34m" << _amount
			  << "\033[0m;closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:\033[34m" << _accountIndex
			  << "\033[0m;p_amount:\033[34m" << _amount
			  << "\033[0m;deposit:\033[34m" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "\033[0m;amount:\033[34m" << _amount
			  << "\033[0m;nb_deposits:\033[34m" << _nbDeposits
			  << "\033[0m" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:\033[34m" << _accountIndex
			  << "\033[0m;p_amount:\033[34m" << _amount
			  << "\033[0m;withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal
			  << ";amount:\033[34m" << _amount
			  << "\033[0m;nb_withdrawals:\033[34m" << _nbWithdrawals
			  << "\033[0m" << std::endl;
	return true;
}

int		Account::checkAmount( void ) const
{
	_displayTimestamp();
	std::cout << "index:\033[34m" << _accountIndex
			  << "\033[0m;amount:\033[34m" << _amount
			  << "\033[0m" << std::endl;
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:\033[34m" << _accountIndex
			  << "\033[0m;amount:\033[34m" << _amount
			  << "\033[0m;deposits:\033[34m" << _nbDeposits
			  << "\033[0m;withdrawals:\033[34m" << _nbWithdrawals
			  << "\033[0m" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	std::cout << "[" << (datetime.tm_year + 1900)
			  << (datetime.tm_mon + 1 < 10 ? "0" : "") << (datetime.tm_mon + 1)
			  << (datetime.tm_mday < 10 ? "0" : "") << datetime.tm_mday
			  << "_"
			  << (datetime.tm_hour < 10 ? "0" : "") << datetime.tm_hour
			  << (datetime.tm_min < 10 ? "0" : "") << datetime.tm_min
			  << (datetime.tm_sec < 10 ? "0" : "") << datetime.tm_sec
			  << "] ";
}