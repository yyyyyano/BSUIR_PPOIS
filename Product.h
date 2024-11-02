#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string> 
using namespace std;

class Product {
	double productCost;
	string productName;
	double productWeight;
	string weightCathegory;

	string GenerateWeightCathegory();

public:
	Product(string productName, double cost, double productWeight);

	void ShowInfo();

	void DiscountRoulette();

	double GetCost();

	string GetWeightCategory();
};

#endif