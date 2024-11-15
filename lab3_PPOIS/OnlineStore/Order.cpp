#include "Order.h"

bool Order::IsInStock() {
	return this->currentQuantity != 0;
}

Order::Order() {};

Order::Order(string name, double price, int currQuantity, string productCategory) :Product(name, price, currQuantity, productCategory) {
	orderCounter++;
	orderIdx = productArticle + "_" + to_string(orderCounter);
	inStock = true;
	orderStatus = "Created";
}

void Order::MakeOrder() {
	if (inStock = IsInStock()) {
		cout << "Order #" << orderIdx << " has been made successfully!\n";
		orderStatus = "Ordered";
		currentQuantity--;
	}
	else cout << "All this products sold out\n";
}

void Order::CancelOrder() {
	cout << "Order #" << orderIdx << " was cancelled successfully!\n";
	orderStatus = "Cancelled";
	inStock = true;
	currentQuantity++;
}

string Order::GetOrderIdx() {
	return orderIdx;
}

void Order::ShowInfo()  {
	Product::ShowInfo();
	cout << "Order idx: " << orderIdx << "\nOrder status: " << orderStatus << endl;
}

void Order::SetStatus(string newStatus) {
	orderStatus = newStatus;

}

string Order::GetStatus() {
	return orderStatus;
}


int Order::orderCounter = 0;