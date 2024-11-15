#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\NotificationSystem.h"
#include "E:\PPOIS\labs\OnlineStore\NotificationSystem.cpp"

TEST(NotificationSystemTest, SendNotificationAndCheck) {
	NotificationSystem a;
	a.SendNotification("Aboba");
	testing::internal::CaptureStdout();
	a.CheckAllNotifications();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Notification: Aboba | Unread\n";
	EXPECT_EQ(output, expected_output);
	a.SendNotification("Biba i Boba");
	testing::internal::CaptureStdout();
	a.CheckAllNotifications();
	string output2 = testing::internal::GetCapturedStdout();
	string expected_output2 = "Notification: Aboba | Read\nNotification: Biba i Boba | Unread\n";
	EXPECT_EQ(output2, expected_output2);
}