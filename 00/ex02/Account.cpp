#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t rawtime;
    std::tm* timeinfo;
    char buffer[80];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
	// std::cout << "[19920104_091532] ";
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
	std::cout << "accounts:" << C_BLUE << Account::getNbAccounts() << C_DEF << ";total:" << C_BLUE << Account::getTotalAmount() << C_DEF
		<< ";deposits:" << C_BLUE << Account::getNbDeposits() << C_DEF << ";withdrawals:" << C_BLUE << Account::getNbWithdrawals() << C_DEF << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::getNbAccounts();
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << C_BLUE << _accountIndex << C_DEF << ";amount:" << C_BLUE << _amount << C_DEF;
	std::cout << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << C_BLUE << _accountIndex << C_DEF << ";amount:" << C_BLUE << _amount << C_DEF;
	std::cout << ";closed" << std::endl;
}


void Account::makeDeposit (int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << C_BLUE << _accountIndex << C_DEF << ";p_amount:" << C_BLUE << _amount << C_DEF;
	if (deposit == 0)
		return ;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";deposit:" << C_BLUE << deposit << C_DEF << ";amount:" << C_BLUE << _amount << C_DEF << ";nb_deposits:" << C_BLUE << _nbDeposits << C_DEF << std::endl;
}

bool Account::makeWithdrawal (int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << C_BLUE << _accountIndex << C_DEF << ";p_amount:" << C_BLUE << _amount << C_DEF;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (0);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << C_BLUE << withdrawal << C_DEF << ";amount:" << C_BLUE << _amount << C_DEF << ";nb_withdrawals:" << C_BLUE << _nbWithdrawals << C_DEF << std::endl;
	return (1);
}

int Account::checkAmount ( void ) const
{
	return (_amount);
}

void Account::displayStatus (void) const
{
	_displayTimestamp();
	std::cout << "index:" << C_BLUE << _accountIndex << C_DEF << ";amount:" << C_BLUE << _amount << C_DEF;
	std::cout << ";deposits:" << C_BLUE << _nbDeposits << C_DEF << ";withdrawals:" << C_BLUE << _nbWithdrawals << C_DEF << std::endl;
}

