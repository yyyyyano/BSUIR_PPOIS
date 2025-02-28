#include "PickUpPoint.h"

bool PickUpPoint::UserPinned(string findLogin) {
	auto it = find_if(pinnedUsers.begin(), pinnedUsers.end(),
		[&](UserAccount* user) { return user->GetLogin() == findLogin; });

	return it != pinnedUsers.end();
}

PickUpPoint::PickUpPoint(int aveCapacity, string address, vector<Product*> orders, vector<UserAccount*> users) :
	Warehouse(aveCapacity, address, orders), pinnedUsers(users) {
	pointID = pointIDcounter;
	pointIDcounter++;
}

void PickUpPoint::IssueParcel(string issuedOrder, UserAccount* issuedUser) {
	if (!goods.empty() && UserPinned(issuedUser->GetLogin())) {
		bool orderFound = false;

		for (Product* product : goods) {
			Order* order = dynamic_cast<Order*>(product);

			if (order && order->GetOrderIdx() == issuedOrder) {
				cout << "Order #" << order->GetOrderIdx() << " was issued to user #" << issuedUser->GetLogin() << endl;
				order->SetStatus("Order was issued");
				DeleteProduct(order->GetArticle());
				orderFound = true;
				issuedUser->GetNotify()->SendNotification("Order #" + issuedOrder + " was issued");
				break;
			}
		}
		if (!orderFound) {
			cout << "\nThere is no Order #" << issuedOrder << endl;
		}
	}
	else {
		cout << "\nError!\n";
	}

}

void PickUpPoint::ReturnParcel(string returningOrder, UserAccount* servedUser) {
	if (!goods.empty() && UserPinned(servedUser->GetLogin())) {
		bool orderFound = false;

		for (Product* product : goods) {
			Order* order = dynamic_cast<Order*>(product);

			if (order && order->GetOrderIdx() == returningOrder) {
				cout << "Order #" << order->GetOrderIdx() << " was returned by user #" << servedUser->GetLogin() << " from POP#" << pointID << endl;
				order->SetStatus("Order was returned");
				DeleteProduct(order->GetArticle());
				orderFound = true;
				servedUser->GetNotify()->SendNotification("Order #" + returningOrder + " was returned");
				break;
			}
		}
		if (!orderFound) {
			cout << "\nThere is no Order #" << returningOrder << endl;
		}
	}
	else {
		cout << "\nError!\n";
	}

}

int PickUpPoint::GetPUPid() {
	return pointID;
}

int PickUpPoint::pointIDcounter = 1;
