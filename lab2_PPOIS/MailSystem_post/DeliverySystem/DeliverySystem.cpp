#include "DeliverySystem.h"


void DeliverySystem::DisplayStatusHistory(Package& package) const {
    PackageStatus* status = package.GetPackageStatus();
    if (status != nullptr) {
        const vector<string>& history = status->GetStatusHistory();
        if (history.empty()) {
            cout << "No status information for this package :( " << package.GetTrackingNumber() << endl;
            return;
        }

        cout << "\nStatus history for package " << package.GetTrackingNumber() << ":\n";
        for (const string& status : history) {
            cout << " - " << status << endl;
        }
    }
    else {
        cout << "No status information for this package " << package.GetTrackingNumber() << endl;
    }
}

void DeliverySystem::NotifyUserAboutDelivery(UserAccount userAccount, Package& package) {
    if (package.GetPackageStatus()->GetpackageStatus() == "Delivered")
        cout << "Notifying user " << userAccount.GetLogin() << " about delivery of " << package.GetTrackingNumber() << endl;
    else {
        cout << "Notifying user " << userAccount.GetLogin() << " that your package " << package.GetTrackingNumber() << " has changed delivery status\n";
        cout << "New status: " << package.GetPackageStatus()->GetpackageStatus() << endl;
    }

}