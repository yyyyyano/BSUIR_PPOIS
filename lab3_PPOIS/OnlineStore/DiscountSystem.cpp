#include "DiscountSystem.h"

DiscountSystem::DiscountSystem() {
	discountTypes = { "Seasonal Discount","Black Friday","Coupon Code", "New Customer Discount","Birthday Discount" };
	promocodes = { "HELLOWORLD","PROMOCODE","QWERTY","BOOLEAN","YEEEEEERRRR" };
}

double DiscountSystem::ApplyDiscount(double& startPrice) {
	startPrice = (startPrice <= 10.00) ? (startPrice * 0.8) :
		(startPrice > 10.00 && startPrice <= 50.00) ? (startPrice * 0.9 + 1.45) : (startPrice - 1.99);
	return startPrice;
}

bool DiscountSystem::HasDiscountType(string findDiscount) const {
	return find(discountTypes.begin(), discountTypes.end(), findDiscount) != discountTypes.end();
}

bool DiscountSystem::HasPromocode(string findPromocode) const {
	return find(promocodes.begin(), promocodes.end(), findPromocode) != promocodes.end();
}

void DiscountSystem::DeleteDiscount(string deletingDiscount) {
	discountTypes.erase(
		remove(discountTypes.begin(), discountTypes.end(), deletingDiscount),
		discountTypes.end()
	);
	promocodes.erase(
		remove(promocodes.begin(), promocodes.end(), deletingDiscount),
		promocodes.end()
	);
}

void DiscountSystem::DisplayDiscounts() const {
	cout << "Available Discount Types:\n";
	for (const auto& discount : discountTypes) {
		cout << " - " << discount << endl;
	}

	cout << "\nAvailable Promocodes:\n";
	for (const auto& promocode : promocodes) {
		cout << " - " << promocode << endl;
	}
}