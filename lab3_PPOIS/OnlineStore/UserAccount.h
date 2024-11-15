#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H

#include "Human.h"
#include "OrderBasket.h"
#include "NotificationSystem.h"
#include <vector>

class UserAccount {
	Human* userInfo;
	string login; 
	string password; 
	string email; 
	vector<Order*> ordersHistory; 
	OrderBasket* userOrderBasket; 
	NotificationSystem* notifications; 
public:
	UserAccount(Human* user, string login, string password, string email, OrderBasket* userOrderBasket, NotificationSystem* notifications);

	void MakeOrder(string buyOrderID);

	void ShowInfo();

	bool CheckPassword(string enteredPassword);

	string GetLogin();

	OrderBasket* GetBasket();

	NotificationSystem* GetNotify();
};



#endif
