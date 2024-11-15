#include "OrderBasket.h"

OrderBasket::OrderBasket(vector<Order*> orders) : myOrders(orders) {
	goodsQuantity = myOrders.size();
}

void OrderBasket::MakeOrderByID(string buyOrderID, Order* buying) {
	for (Order* good : myOrders) {
		if (good->GetOrderIdx() == buyOrderID) {
			cout << "OD #" << good->GetOrderIdx() << " was ordered!\n";
			good->MakeOrder();
			buying = good;
			myOrders.erase(
				remove(myOrders.begin(), myOrders.end(), good),
				myOrders.end()
			);
			goodsQuantity--;
			return;
		}
	}
	cout << "No matches with Article " << buyOrderID << " found among " << goodsQuantity << " products in your Orders basket : (\n";
}

void OrderBasket::ShowInfo() {
	cout << "Order basket: \n";
	if (myOrders.empty()) cout << "Your order basket is empty!\n";
	else {
		for (Order* ord : myOrders) {
			cout <<" - "<< ord->GetOrderIdx() << endl;
		}
		cout << "\nQuantity of goods: " << goodsQuantity << endl;
	}
}

double OrderBasket::GetTotalPrice() {
	double totalPrice = 0;
	if (myOrders.empty())
		cout << "Your order basket is empty!\n";
	else {
		for (Order* ord : myOrders) {
			totalPrice += ord->GetPrice();
		}
	}
	return totalPrice;
}

bool OrderBasket::IsInBasket(Order* findOrder) {
	for (Order* order : myOrders) {
		if (order == findOrder) {
			return true;
		}
	}
	return false;
}
