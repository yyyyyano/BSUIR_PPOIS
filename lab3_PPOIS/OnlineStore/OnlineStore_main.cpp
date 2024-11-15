#include "CallCenter.h"
#include "CallCenterOperator.h"
#include "Date.h"
#include "DiscountSystem.h"
#include "Employee.h"
#include "NotificationSystem.h"
#include "OnlineStore.h"
#include "Order.h"
#include "OrderBasket.h"
#include "PickUpPoint.h"
#include "PickUpPointWorker.h"
#include "Product.h"
#include "SearchSystem.h"
#include "UserAccount.h"
#include "Warehouse.h"

int main() {
	Date bday(9, 11, 2006);
	bday.ShowDate();
	cout << endl;
	Human me("yana", "bankevich", bday, "+375256974761");
	me.ShowInfo();
	cout << endl;

	CallCenterOperator Yana("yana", "bankevich", bday, "+375256974761", "call center operator", 15, "payments",14);
	Yana.ShowInfo();
	Yana.IsAvailable();
	Yana.Work();

	cout << endl;
	DiscountSystem a;
	if (a.HasDiscountType("QWERTY")) cout << "We have it!" << endl;
	else cout << "We don`t have it :("<<endl;

	cout << endl;
	Product apple("apple", 10, 100, "food");
	/*apple.GetDiscounts().DisplayDiscounts();
	apple.ChangePriceWithDiscount("QWERTY");
	cout << endl;
	apple.GetDiscounts().DisplayDiscounts();*/
	cout << endl;
	apple.ShowInfo();

	cout << endl;
	Product pear("pear", 11, 1, "food");
	pear.ShowInfo();
	cout << endl;
	Product car("bmw", 12345, 11, "mobility");
	car.ShowInfo();
	vector<Product*> products = { &apple,&pear,&car };
	SearchSystem ss(products);
	cout << "\nFOUND\n" << endl;
	vector <Product*> findCat= ss.FindProductsByCategory("mobility");
	if (findCat.empty()) cout << "No matches!\n";
	else {
		for (Product* prod : findCat) {
			prod->ShowInfo();
			cout << endl;
		}
	}

	cout << endl;
	Product* findArt=ss.FindProductByArticle("Art_bmw3");
	if(findArt!=nullptr)
		findArt->ShowInfo();

	cout << endl;
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	Order pears("pears", 1, 1, "food");
	Banana.ShowInfo();
	Banana.MakeOrder();
	cout << endl;
	Banana.ShowInfo();
	cout << endl;
	vector<Order*> ob= { &Banana,&bag };
	OrderBasket orrder(ob);
	if (orrder.IsInBasket(&pears))cout << "\n\nYAAAAAAS";
	else cout << "\n\nNOOOO";
	//orrder.ShowInfo();
	//double to1t = orrder.GetTotalPrice();
	//cout << "\nTotal price: " << to1t << endl;
	//Order buy;
	//orrder.MakeOrderByID("Art_ban4_1",&buy);
	//orrder.ShowInfo();
	//double tot = orrder.GetTotalPrice();
	//cout << "\nTotal price: " << tot<<endl;
	//double price = 60;
	//a.ApplyDiscount(price);
	//cout << "\nNew price: " << price << endl;
	/*NotificationSystem notif();
	UserAccount userme(&me, "yanix", "121", "bankevi4@gmail.com", orrder, &notif);*/
	/*cout << endl;
	vector<Employee*> staff;*/
	vector<Product*> prod = { &pear,&car,&Banana };
	/*Warehouse boo(4, "abobini 18", prod);
	boo.AcceptProducts(ob);
	boo.ShowGoods();
	cout << endl;
	boo.DeleteProduct("Art_bmw3");
	cout << endl;
	boo.ShowGoods();*/

	cout << endl<<endl<<endl<<endl<<endl;
	
	NotificationSystem notificSys;
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	vector<UserAccount*> users = { &user };
	PickUpPoint point(100, "Abobino 12", prod, users);
	PickUpPointWorker puper("katya", "rublevskaya", bday, "+375256788765", "puper", 12,5,&point);
	vector<PickUpPointWorker*> ppstaff = { &puper };


	cout << endl;
	point.ShowGoods();
	cout << endl;
	/*point.ReturnParcel("Art_ba4_1",&user);
	cout << endl;
	point.ShowGoods();*/
	
	/*cout << endl;
	puper.ReturnParcel("Art_ban4_1", &user);
	cout << endl;
	point.ShowGoods();*/

	cout << endl << endl;
	CallCenterOperator meow("Yana", "Bank", bday, "+375256974761", "operator", 12, "confirmation", 12);
	meow.OrderConfirmation(&Banana, &user);


	cout << endl << endl;
	NotificationSystem notifSystem;

	notifSystem.SendNotification("Your order has been shipped.");
	notifSystem.SendNotification("New product added to your wishlist.");
	notifSystem.SendNotification("A discount is available on your favorite products.");

	cout << "All notifications:\n";
	notifSystem.CheckAllNotifications();

	cout << "\nUpdated notifications:\n";
	notifSystem.CheckAllNotifications();

	cout << endl << endl;
	vector<string> atr = { "d" };
	vector<Warehouse*> ware;
	OnlineStore shop(&ss, "shop", users, ware);
	shop.LogUser(&user);
	user.GetNotify()->CheckAllNotifications();
	cout << endl;
	vector<Product*>founnd;
	shop.CheckGoods(atr,founnd);

	return 0;
}