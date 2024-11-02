#ifndef DELIVERY_SYSTEM_H
#define DELIVERY_SYSTEM_H
#include "Package.h"
#include "UserAccount.h"

class DeliverySystem {
public:

    void DisplayStatusHistory(Package& package) const;

    void NotifyUserAboutDelivery(UserAccount userAccount, Package& package);
};


#endif
