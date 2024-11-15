#ifndef ORDER_BASKET_H
#define ORDER_BASKET_H

#include "Order.h"

class OrderBasket {
	vector<Order*> myOrders; 
	int goodsQuantity;
public:
	OrderBasket(vector<Order*> orders);

	void MakeOrderByID(string buyOrderID, Order* buying);

	void ShowInfo();

	double GetTotalPrice();

	bool IsInBasket(Order* findOrder);
};

#endif