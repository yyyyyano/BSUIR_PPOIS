#include "UserAccount.h"

UserAccount::UserAccount(Human* user, string login, string password, string email, OrderBasket* userOrderBasket, NotificationSystem* notifications) :
	userInfo(user), login(login), password(password), email(email), ordersHistory(), userOrderBasket(userOrderBasket), notifications(notifications) {};

void UserAccount::MakeOrder(string buyOrderID) {
	Order buying;
	userOrderBasket->MakeOrderByID(buyOrderID, &buying);
	notifications->SendNotification("Order #" + buyOrderID + " was made");
	ordersHistory.push_back(&buying);
	cout << "User #" << login << " ordered OD #" << buying.GetOrderIdx() << " successfully\n";
}

void UserAccount::ShowInfo() {
	userInfo->ShowInfo();
	cout << "Login: " << login << "Email: " << email << "\nOrders history:\n ";
	if (!ordersHistory.empty()) {
		for (Order* ord : ordersHistory) {
			cout << " - " << ord->GetArticle() << endl;
		}
	}
	cout << "Order basket: \n";
	userOrderBasket->ShowInfo();
}

bool UserAccount::CheckPassword(string enteredPassword) {
	return enteredPassword == password;
}

string UserAccount::GetLogin() {
	return login;
}

OrderBasket* UserAccount::GetBasket() {
	return userOrderBasket;
}

NotificationSystem* UserAccount::GetNotify() {
	return notifications;
}
