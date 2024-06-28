#include "BankingApp.h"

void BankingApp::displayWelcomeMessage() {
	std::cout << "Welcome to Airgead Banking App!" << std::endl;
}

void BankingApp::getUserInput() {
	// Input validation for initial investment amount
	while (true) {
		std::cout << "Enter Initial Investment Amount: ";
		std::cin >> initialInvestment;
		if (initialInvestment > 0) break;
		std::cout << "Invalid input. Please enter a positive number." << std::endl;
	}
	//Input validation for monthly deposit
	while (true) {
		std::cout << "Enter Monthly Deposit: ";
		std::cin >> monthlyDeposit;
		if (monthlyDeposit >= 0) break; // monthlyDeposit can be zero or positive
		std::cout << "Invalid input. Please enter a non-negative number." << std::endl;
	}

	// Input validation for annual interest rate
	while (true) {
		std::cout << "Enter Annual Interest Rate: ";
		std::cin >> annualInterestRate;
		if (annualInterestRate > 0) break;
		std::cout << "Invalid input. Please enter a positive number." << std::endl;
	}

	// Input validation for number of years
	while (true) {
		std::cout << "Enter Number of Years: ";
		std::cin >> numberOfYears;
		if (numberOfYears > 0) break;
		std::cout << "Invalid input. Please enter a positive integer." << std::endl;
	}
}

void BankingApp::displayInputSummary() {
	std::cout << "\nSummary of Input: " << std::endl;
	std::cout << "Initial Investment Amount: $" << initialInvestment << std::endl;
	std::cout << "Monthly Deposit: $" << monthlyDeposit << std::endl;
	std::cout << "Annual Interest Rate: " << annualInterestRate << "%" << std::endl;
	std::cout << "Number of Years: " << numberOfYears << std::endl;
	std::cout << "Press any key to continue..." << std::endl;
	std::cin.ignore();
	std::cin.get();
}
void BankingApp::calculateAndDisplayBalanceWithoutMonthlyDeposit() {
	double balance = initialInvestment;
	double totalInterestEarned = 0.0;
	double monthlyInterestRate = (annualInterestRate / 100) / 12;

	for (int year = 1; year <= numberOfYears; ++year) {
		double interestEarnedThisYear = 0.0;
		for (int month = 1; month <= 12; ++month) {
			double monthlyInterest = balance * monthlyInterestRate;
			interestEarnedThisYear += monthlyInterest;
			balance += monthlyInterest;
		}
		totalInterestEarned += interestEarnedThisYear;
		printDetails(year, balance, interestEarnedThisYear);
	}
}

void BankingApp::calculateAndDisplayBalanceWithMonthlyDeposit() {
	double balance = initialInvestment;
	double monthlyInterestRate = annualInterestRate / 100 / 12;
	double interestEarnedThisYear = 0.0;

	for (int year = 1; year <= numberOfYears; ++year) {
		for (int month = 1; month <= 12; ++month) {
			double monthlyInterest = balance * monthlyInterestRate;
			interestEarnedThisYear += monthlyInterest;
			balance += monthlyInterest;
			balance += monthlyDeposit;
		}
		printDetails(year, balance, interestEarnedThisYear);
		interestEarnedThisYear = 0.0;
	}
}

void BankingApp::printDetails(int year, double yearEndBalance, double interestEarned) {
	std::cout << year << "\t\t$" << std::fixed << std::setprecision(2) << yearEndBalance << "\t\t$" << interestEarned << std::endl;
}

void BankingApp::run() {
	displayWelcomeMessage();
	getUserInput();
	displayInputSummary();

	std::cout << "Year\tYear End Balance\tYear End Earned Interest" << std::endl;
	calculateAndDisplayBalanceWithoutMonthlyDeposit();

	std::cout << "\nYear\tYear End Balance\tYear End Earned Interest (With Monthly Deposit)" << std::endl;
	calculateAndDisplayBalanceWithMonthlyDeposit();

	std::cout << "Thank you for using Airgead Banking App!" << std::endl;

}