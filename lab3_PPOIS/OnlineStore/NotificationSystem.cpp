#include "NotificationSystem.h"

NotificationSystem::NotificationSystem() : notifications(), notificationsCount(0) {};

void NotificationSystem::SendNotification(string newNotification) {
	notifications.push_back(make_pair(newNotification, false));
	notificationsCount++;
}

void NotificationSystem:: CheckAllNotifications() {
	for (size_t i = 0; i < notificationsCount; i++) {
		cout << "Notification: " << notifications[i].first << " | ";
		if (!notifications[i].second) {
			cout << "Unread" << endl;
			notifications[i].second = true;
		}
		else {
			cout << "Read" << endl;
		}
	}
}