#include "UserAccount.h"

int UserAccount::counterAccountID = 0;

UserAccount::UserAccount(Customer* userInfo, string login, string password, string email) {
	this->userInfo = userInfo;
	this->accountID = counterAccountID;
	this->login = login;
	this->password = password;
	if (this->IsValidEmail(email))
		this->email = email;
	else
		cout << "\nIncorrect email format!\n";
	counterAccountID++;
}

bool UserAccount::IsValidEmail(const string& email) { //
	size_t atPosition = email.find('@');
	if (atPosition == string::npos || atPosition == 0 || atPosition == email.length() - 1)
		return false;

	size_t dotPosition = email.find('.', atPosition);
	if (dotPosition == string::npos || dotPosition == atPosition + 1 || dotPosition == email.length() - 1)
		return false;
	return true;
}

string UserAccount::GetLogin() {
	return login;
}

void UserAccount::ShowUserInfo() { //
	cout << "\naccountID:\t" << this->accountID
		<< "\nlogin:\t" << this->login
		<< "\nemail:\t" << this->email;
}

bool UserAccount::CheckPassword(string enteredPassword) { //
	return enteredPassword == password;
}