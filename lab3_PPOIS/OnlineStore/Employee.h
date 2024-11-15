#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Human.h"

enum workerStatus {
 	FREE,
    ONLINE,
    UNAVAILABLE
};

class Employee :public virtual Human {
protected:
	string employeeID; 
	string position;
	static int employeeIDcounter; 
	workerStatus isFree;
public:

	Employee(string name, string surname, Date bday, string phoneNum, string position);

	void virtual Work() = 0;

	void ShowInfo() override;

	void IsAvailable();

	workerStatus GetAvailability();
};


#endif