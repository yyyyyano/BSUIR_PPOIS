#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H

#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

class UserAccount {
	Customer* userInfo;
	int accountID;
	string login;
	string password;
	string email;
	static int counterAccountID;

public:
	UserAccount(Customer* userInfo, string login, string password, string email);

	bool IsValidEmail(const string& email); //

	string GetLogin();

	//string GetEmail() {
	//	return email;
	//}

	void ShowUserInfo();

	bool CheckPassword(string enteredPassword); //
};



#endif
