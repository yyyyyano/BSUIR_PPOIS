#ifndef ONLINE_STORE_H
#define ONLINE_STORE_H

#include "SearchSystem.h"
#include "UserAccount.h"
#include "PickUpPoint.h"


class OnlineStore {
	SearchSystem* searching; 
	string storeName;  
	vector<UserAccount*> users;
	vector <Warehouse*> logs; 
public:
	OnlineStore(SearchSystem* SS, string storeName, vector<UserAccount*> users, vector<Warehouse*> logs);

	void LogUser(UserAccount* newUser);

	void CheckGoods(vector<string> articles, vector<Product*>& foundGoods);
};

#endif
