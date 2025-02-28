#include "Product.h"

string Product::CreateProductArticle() {
	acticleCounter++;
	return "Art_" + productName.substr(0, 3) + to_string(acticleCounter);
}

Product::Product() {};

Product::Product(string name, double price, int currQuantity, string productCategory) :
	productName(name), productPrice(price), currentQuantity(currQuantity), productCategory(productCategory), productDiscount() {
	this->productArticle = CreateProductArticle();
}

void Product::ChangePriceWithDiscount(string discountType) {
	bool discountIsApplyed = false;

	if (productDiscount.HasDiscountType(discountType)) {
		productPrice = productDiscount.ApplyDiscount(productPrice);
		discountIsApplyed = true;
	}
	else if (productDiscount.HasPromocode(discountType)) {
		productPrice *= 0.6;
		discountIsApplyed = true;
	}

	if (discountIsApplyed) {
		productDiscount.DeleteDiscount(discountType);
		cout << "Your discount was applyed succesfully! New price: " << productPrice << endl;
	}
	else cout << "Unfortunately we don`t have this discount :(\n";

};

string Product::GetCategory() {
	return productCategory;
}

string Product::GetArticle() {
	return productArticle;
}

double Product::GetPrice() {
	return productPrice;
}

void  Product::ShowInfo() {
	cout << "Name: " << productName << "\nPrice: " << productPrice << "\nArticle: " << productArticle << "\nCurrent quantity: " << currentQuantity << "\nCategory: " << productCategory << endl;
}

int Product::GetQuantity() {
	return currentQuantity;
}


int Product::acticleCounter = 0;
