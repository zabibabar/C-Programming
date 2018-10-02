#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "employee.h"

#define TAX_RATE  0.15f
#define FULL_TIME 40
#define OVERTIME_RATE_MULTIPLIER 1.5f

void getSalaryInfo(struct employee* emp);
int findMax(struct employee a[], int n);
void selectionSort(struct employee a[], int n);

int main(int argc, char* argv[])
{
    struct employee *p, *q;
    double bonus;

    if(argc < 3)
    {
        printf("Usage: payroll <input filename> <output filename>\n\n");
        return 1;
    }

    //Build list of employees
    struct employee* list = buildEmployeeList(argv[1]);

    //calculate employee income
    for(p = list; p != NULL; p = p->next)
    {
        getSalaryInfo(p); //pass pointer to struct
    }

    if (argc > 4){
   		q = search(list, argv[3]);
	    if(q != NULL)
	    {
	    	sscanf(argv[4],"%f", &bonus);
	    	q->netInc += bonus;
	    }
    }

   	//Write employee income to output file
    writeSalaryInfoToFile(list, argv[2]);

    clearList(list);
}

//calculate net income and taxes withheld - adapt your code from project 1!
//Store the results in the corresponding members of the struct pointed to by 'emp'
void getSalaryInfo(struct employee* emp)
{
	if (emp->hours > 40)
	{
		emp->netInc = 0.85*((FULL_TIME * emp->rate) + ((emp->hours - FULL_TIME) * (emp->rate * 1.5)));
		emp->tax = 0.15*((FULL_TIME * emp->rate) + ((emp->hours - FULL_TIME) * (emp->rate * 1.5)));
	}
	else 
	{
		emp->netInc = 0.85*(emp->hours * emp->rate);
		emp->tax = 0.15*(emp->hours * emp->rate);
	}
}