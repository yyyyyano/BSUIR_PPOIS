#ifndef PRODUCT_H
#define PRODUCT_H

#include "DiscountSystem.h"

using namespace std;

class Product {

	string CreateProductArticle();

protected:
	string productName; 
	double productPrice; 
	string productArticle; 
	static int acticleCounter; 
	int currentQuantity; 
	string productCategory;
	DiscountSystem productDiscount;
public:
	Product();

	Product(string name, double price, int currQuantity, string productCategory);

	void ChangePriceWithDiscount(string discountType);

	string GetCategory();

	string GetArticle();

	double GetPrice();

	int GetQuantity();

	void virtual ShowInfo();
};

#endif
