#include "Account.hpp"

int	main(void)
{
	Account account(45);
	Account account2(60);

	Account::displayAccountsInfos();

	account.displayStatus();
	account2.displayStatus();

	account.makeDeposit(5);
	account2.makeDeposit(5);

	account.displayStatus();
	account2.displayStatus();
	return (0);
}