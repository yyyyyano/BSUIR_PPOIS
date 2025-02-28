#include "Warehouse.h"

Warehouse::Warehouse(int aveCapacity, string address, vector<Product*> orders) :
	averageCapacity(aveCapacity), address(address), goods(orders) {
	currentCapacity = orders.size();
};

void Warehouse::AcceptProducts(vector<Product*> newGoods) {
	int freeSpace = averageCapacity - currentCapacity;
	int acceptedGoods = 0;

	for (Product* product : newGoods) {
		if (acceptedGoods < freeSpace) {
			goods.push_back(product);
			acceptedGoods++;
		}
		else {
			cout << "There is no space for all products! Still " << (newGoods.size() - acceptedGoods) << " haven`t been accepted\n";
			break;
		}
	}
	currentCapacity += acceptedGoods;
	cout << acceptedGoods << " goods were accepted!\n";
}

void Warehouse::DeleteProduct(string deleteArticle) {
	if (!goods.empty()) {
		bool flag = false;
		for (Product* product : goods) {
			if (product->GetArticle() == deleteArticle) {
				flag = true;
				goods.erase(
					remove(goods.begin(), goods.end(), product),
					goods.end()
				);
				cout << "Product #" << deleteArticle << " was removed from the warehouse\n";
				break;
			}
		}
		if (flag = false) cout << "There is no product #" << deleteArticle << " in this warehouse\n";
	}
	else cout << "There is no products in thw warehouse\n";
}

void Warehouse::ShowGoods() {
	for (Product* product : goods) {
		cout << " - " << product->GetArticle() << endl;
	}
}
