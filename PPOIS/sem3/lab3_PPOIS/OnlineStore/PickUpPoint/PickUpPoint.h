#ifndef PICK_UP_POINT_H
#define PICK_UP_POINT_H

#include "Warehouse.h"
#include "UserAccount.h"

class PickUpPoint : public Warehouse {
	int pointID; 
	static int pointIDcounter; 
	vector<UserAccount*> pinnedUsers; 

	bool UserPinned(string findLogin);

public:
	PickUpPoint(int aveCapacity, string address, vector<Product*> orders, vector<UserAccount*> users);

	void IssueParcel(string issuedOrder, UserAccount* issuedUser);

	void ReturnParcel(string returningOrder, UserAccount* servedUser);

	int GetPUPid();
};



#endif
