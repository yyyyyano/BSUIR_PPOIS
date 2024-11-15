#ifndef SEARCH_SYSTEM_H
#define SEARCH_SYSTEM_H

#include "Product.h"

class SearchSystem {
	vector<Product*> goods;
	int averageGoodsCount;
public:
	SearchSystem(vector<Product*> goods);

	vector<Product*> FindProductsByCategory(string findCategory);

	Product* FindProductByArticle(string findArticle);
};

#endif
