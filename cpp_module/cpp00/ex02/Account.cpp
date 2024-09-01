#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    time_t	time_stamp;
	char	buf[16];

	time(&time_stamp);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&time_stamp));
	std::cout << "[" << buf << "]";
}

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

void Account::makeDeposit(int deposit) {
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    this->_amount += deposit;
    this->_nbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    this->_amount -= withdrawal;
    if (checkAmount() == 0) {
        _displayTimestamp();
        this->_amount += withdrawal;
        std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    this->_nbWithdrawals++;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    if (this->_amount < 0) {
        return 0;
    }
    return this->_amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::~Account(void) {
    Account::_totalAmount -= this->_amount;
    Account::_nbAccounts--;
    Account::_totalNbDeposits -= this->_nbDeposits;
    Account::_totalNbWithdrawals -= this->_nbWithdrawals;
    
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}