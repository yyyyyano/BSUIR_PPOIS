#ifndef ORDER_H
#define ORDER_H

#include "Product.h"

class Order :public Product {
	string orderIdx; 
	static int orderCounter; 
	bool inStock; 
	string orderStatus;

	bool IsInStock();

public:
	Order();

	Order(string name, double price, int currQuantity, string productCategory);

	void MakeOrder();

	void CancelOrder();

	string GetOrderIdx();

	void ShowInfo() override;

	void SetStatus(string newStatus);

	string GetStatus();
};


#endif