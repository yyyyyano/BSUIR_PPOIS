#include "SearchSystem.h"

SearchSystem::SearchSystem(vector<Product*> goods) : goods(goods) {
	averageGoodsCount = goods.size();
};

vector<Product*> SearchSystem::FindProductsByCategory(string findCategory) {
	vector<Product*> foundProducts;
	for (Product* product : goods) {
		if (product->GetCategory() == findCategory)
			foundProducts.push_back(product);
	}
	return foundProducts;
}

Product* SearchSystem::FindProductByArticle(string findArticle) {
	for (Product* product : goods) {
		if (product->GetArticle() == findArticle)
			return product;
	}
	cout << "No matches found among " << averageGoodsCount << " products :(\n";
	return nullptr;
}