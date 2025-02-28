#ifndef PAYMENT_H
#define PAYMENT_H
#include "Package.h"
#include "Cashier.h"

class Payment {
	string paymentID;
	Package* packageInfo;
	double amount;
	string paymentMethod;
	bool transactionWasProcessed;

public:
	Payment(Package* packageInfo, string paymentMethod);

	void ProcessPayment(string transactionBankAccount, Cashier* cashier);

	void ProcessRefund(string transactionBankAccount, Cashier* cashier);

	bool GetTransactionFlag();
};

#endif
