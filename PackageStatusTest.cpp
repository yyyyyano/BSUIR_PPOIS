#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\PackageStatus.h"
#include "E:\PPOIS\labs\MailSystem_post\PackageStatus.cpp"


TEST(PackageStatusTest, ChangeStatusTest) {
	PackageStatus packst("The package was created");
	EXPECT_EQ(packst.GetpackageStatus(), "The package was created");
	packst.ChangeStatus("Waiting for transaction");
	EXPECT_EQ(packst.GetpackageStatus(), "Waiting for transaction");
}

TEST(PackageStatusTest, IsDelivered_ExpectTrue) {
	PackageStatus packst("The package was created");
	packst.ChangeStatus("Delivered");
	EXPECT_TRUE(packst.IsDelivered());
}

TEST(PackageStatusTest, IsDelivered_ExpectFalse) {
	PackageStatus packst("The package was created");
	packst.ChangeStatus("Waiting for transaction");
	EXPECT_FALSE(packst.IsDelivered());
}
