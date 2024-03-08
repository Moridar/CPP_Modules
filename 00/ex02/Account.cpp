#include "Account.hpp"

void	Account::_displayTimestamp( void )
{
	std::cout << "[20140315_143012]";
}
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::getNbAccounts();
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account(void)
{

}


void Account::makeDeposit (int deposit )
{
	if (deposit == 0)
		return ;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_amount += deposit;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal (int withdrawal)
{
	if (_amount < withdrawal)
		return (0);
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (1);
}

int Account::checkAmount ( void ) const
{
	return (_amount);
}

void Account::displayStatus (void) const
{

}

