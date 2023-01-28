#include <stdio.h>
#include "employee.h"
#include "heap.h"
#include <string.h>

#define MAX_EMPLOYEES 5
#define MAX_INPUT_LEN 128	/** maximum allowed input length */

/// @brief creates the employee array
/// @param outA the array to hold the employee data
void _debug_createEmployeeArray(Employee *outA)
{

	// fill in test employee data;
	struct Employee a;
	strcpy(a.name, "David");
	a.salary = 60000;
	outA[0] = a;

	struct Employee b;
	strcpy(b.name, "Gabe");
	b.salary = 40000;
	outA[1] = b;

	struct Employee c;
	strcpy(c.name, "Katie");
	c.salary = 70000;
	outA[2] = c;

	struct Employee d;
	strcpy(d.name, "Gabe");
	d.salary = 10000;
	outA[3] = d;

	struct Employee e;
	strcpy(e.name, "Joan");
	e.salary = 70000;
	outA[4] = e;




}


/**
 * @brief fills the employee array with value from the user
 * @param outA array to fill 
*/
void createEmployeeArray(Employee *outA){
	for(int i = 0; i< MAX_EMPLOYEES; i++){
		//get employee details
		printf("Name: ");
		char name[MAX_INPUT_LEN];
		scanf("%s", name);

		printf("Salary: ");
		int salary;
		scanf("%d", &salary);
		printf("\n");

		//create new employee and update array
		struct Employee e;
		strcpy(e.name, name);
		e.salary = salary;
		outA[i] = e;
		
	}
}



int main(int argc, char *argv[])
{

	//initialization
	Employee outA[MAX_EMPLOYEES];
	createEmployeeArray(outA);

	//sort
	heapSort(outA, MAX_EMPLOYEES);

	//print
	printList(outA, MAX_EMPLOYEES);

	return 0;
}
