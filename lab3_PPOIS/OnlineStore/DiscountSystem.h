#ifndef DISCOUNT_SYSTEM_H
#define DISCOUNT_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DiscountSystem {
	vector<string> discountTypes;
	vector<string>promocodes;

public:
	DiscountSystem();
	
	double ApplyDiscount(double& startPrice);

	bool HasDiscountType(string findDiscount) const;

	bool HasPromocode(string findPromocode) const;

	void DeleteDiscount(string deletingDiscount);

	void DisplayDiscounts() const;
};

#endif
