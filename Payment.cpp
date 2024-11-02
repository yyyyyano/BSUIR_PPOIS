#include "Payment.h"

Payment::Payment(Package* packageInfo, string paymentMethod)
	:paymentMethod(paymentMethod), packageInfo(packageInfo) {
	transactionWasProcessed = false;
	amount = packageInfo->GetPackageSending().GetCost() * 1.12;
	paymentID = packageInfo->GetTrackingNumber() + paymentMethod.substr(0, 3);
}
void Payment::ProcessPayment(string transactionBankAccount, Cashier* cashier) {//
	if (paymentMethod == "card")
		cout << "\nPayment #" << paymentID << " has been sent to bank acc #" << transactionBankAccount << "\nAmount: " << amount;
	else
		cout << "\nPayment #" << paymentID << " was processed by cashier " << cashier->GetFullName() << "\nAmount: " << amount;
	packageInfo->GetPackageStatus()->ChangeStatus("The package payment was approved");
	transactionWasProcessed = true;
}
void Payment::ProcessRefund(string transactionBankAccount, Cashier* cashier) {//
	if (transactionWasProcessed) {
		if (paymentMethod == "card") {
			cout << "\nRefund for payment #" << paymentID << " is being processed.\n";
			cout << "Refunding amount: " << amount << " to bank account #" << transactionBankAccount << endl;
			packageInfo->GetPackageStatus()->ChangeStatus("The package payment was refunded");
		}
		else
			cout << "\nRefund for payment #" << paymentID << " is processed by cashier " << cashier->GetFullName() << endl;
		transactionWasProcessed = false;
		packageInfo->GetPackageStatus()->ChangeStatus("The package payment was refunded");
	}
	else {
		cout << "No transaction found for payment ID: " << paymentID << ". Refund cannot be processed." << endl;
	}
}

bool Payment::GetTransactionFlag() {
	return transactionWasProcessed;
}