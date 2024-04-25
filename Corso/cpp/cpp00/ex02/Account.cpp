#include "./Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = getNbAccounts();
	_nbAccounts++;
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount<< ";"
			  << "created" << "\n";
}

Account::Account()
{
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = getNbAccounts();
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount<< ";"
			  << "created" << "\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount<< ";"
			  << "closed" << "\n";
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount()<< ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << "\n";
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex << ";"
			  << "p_amount:" <<  this->_amount - deposit << ";"
			  << "deposit:" <<  deposit << ";"
			  << "amount:" <<   this->_amount<< ";"
			  << "nb_deposits:" <<  this->_nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	bool	success = false;

	_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex << ";"
			  << "p_amount:" <<  this->_amount << ";";
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		success = true;
		std::cout << "withdrawal:" << withdrawal << ";"
				  << "amount:" <<  this->_amount << ";"
				  << "nb_withdrawals:" <<  this->_nbWithdrawals << "\n";
	}
	else
		std::cout << "withdrawal:" << "refused" << "\n";
	return success;

}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex << ";"
			  << "amount:" <<  this->_amount << ";"
			  << "deposits:" <<  this->_nbDeposits << ";"
			  << "withdrawals:" <<  this->_nbWithdrawals << "\n";
}

void Account::_displayTimestamp( void )
{
	// Get the current time
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	// Print the timestamp
	std::cout << "["
			  << (now->tm_year + 1900)
			  << (now->tm_mon + 1)
			  << now->tm_mday << '_'
			  << now->tm_hour
			  << now->tm_min
			  << now->tm_sec
			  << "] ";
	}
