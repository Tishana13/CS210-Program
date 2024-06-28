#ifndef BANKING_APP_H_
#define BANKING_APP_H_

#include <iostream>
#include <iomanip>
#include <stdexcept>

class BankingApp {
private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterestRate;
	int numberOfYears;

	void printDetails(int year, double yearEndBalance, double interestEarned);

public:
	void displayWelcomeMessage();
	void getUserInput();
	void displayInputSummary();
	void calculateAndDisplayBalanceWithoutMonthlyDeposit();
	void calculateAndDisplayBalanceWithMonthlyDeposit();
	void run();
};

#endif // BANKING_APP_H_