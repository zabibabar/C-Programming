#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_NAME_LEN 15
#define MAX_NUM_EMPLOYEES 10

struct employee {
	char name[MAX_NAME_LEN+1];
	int id;
	double hours;
	double rate;
	double netInc;
	double tax;
	struct employee *next;
};

struct employee *buildEmployeeList(char* filename);
int writeSalaryInfoToFile(struct employee* list, char* filename);

#endif //EMPLOYEE_H
