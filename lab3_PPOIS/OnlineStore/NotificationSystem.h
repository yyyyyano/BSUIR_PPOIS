#ifndef NOTIFICATION_SYSTEM_H
#define NOTIFICATION_SYSTEM_H

#include <iostream>
#include<vector>
#include <string>
using namespace std;

class NotificationSystem {
	vector<pair<string,bool>> notifications; 
	int notificationsCount; 
public:
	NotificationSystem() ;

	void SendNotification(string newNotification);

	void CheckAllNotifications();
};

#endif
