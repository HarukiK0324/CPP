#include "Account.hpp"
#include <iostream>

static int Account::getNbAccounts()
{
	return _nbAccounts;
}

static int	getTotalAmount( void )
{
	return _totalAmount;
}

static int	getNbDeposits( void )
{
	return _totalNbDeposits;
}

static int	getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

static void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void Account::Account( int initial_deposit )
{
	_nbAccounts++;
	_totalAmount += _initial_deposit;
	_accountIndex = _nbAccounts - 1;
	_amount = _initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}
Account::~Account( void )
{

}

void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

}

int		Account::checkAmount( void ) const
{

}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}
