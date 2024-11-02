#include "Product.h"

string Product::GenerateWeightCathegory() { //
	string cathegory = (productWeight < 3) ? "light" :
		(productWeight < 10) ? "medium" : "heavy";
	return cathegory;
}

Product::Product(string productName, double cost, double productWeight)
	:productName(productName), productCost(cost), productWeight(productWeight) {
	weightCathegory = GenerateWeightCathegory();
};

void Product::ShowInfo() { //
	cout << "\nProduct name: " << productName
		<< "\nProduct cost: " << productCost
		<< "\nProduct weight: " << productWeight
		<< "\nWeight cathegory: " << weightCathegory << endl;
}

void Product::DiscountRoulette() { //
	if (productWeight <= 0.32 && !productName.empty() && (productName[0] >= 'A' && productName[0] <= 'L'))
		productCost *= 0.85;
	else
		productCost *= 1.05;
}

double Product::GetCost() {
	return productCost;
}

string Product::GetWeightCategory() {
	return weightCathegory;
}