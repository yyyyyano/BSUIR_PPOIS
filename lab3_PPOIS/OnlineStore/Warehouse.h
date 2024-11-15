#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Employee.h"
#include "Product.h"

class Warehouse {
protected:
	int averageCapacity; 
	int currentCapacity; 
	string address; 
	vector<Product*> goods;
public:
	Warehouse(int aveCapacity, string address, vector<Product*> orders);

	void AcceptProducts(vector<Product*> newGoods);

	void DeleteProduct(string deleteArticle);

	void ShowGoods();
};


#endif