#include "OnlineStore.h"

OnlineStore::OnlineStore(SearchSystem* SS, string storeName, vector<UserAccount*> users, vector<Warehouse*> logs) :
	searching(SS), storeName(storeName), users(users), logs(logs) {};

void OnlineStore::LogUser(UserAccount* newUser) {
	users.push_back(newUser);
	newUser->GetNotify()->SendNotification("Welcome to online store <" + storeName + "> !");
}

void OnlineStore::CheckGoods(vector<string> articles, vector<Product*>& foundGoods) {
	bool flag = false;
	for (string atr : articles) {
		foundGoods.push_back(searching->FindProductByArticle(atr));
	}
	for (Product* prod : foundGoods) {
		if (prod != nullptr) {
			flag - true;
			prod->ShowInfo();
			cout << endl;
		}
	}
	if (flag == false) cout << "There is no goods with this articles\n";
}