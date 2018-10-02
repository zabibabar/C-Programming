#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "linkedList.h"

struct employee *buildEmployeeList(char* filename)
{
	struct employee *new;
	struct employee *temp;
	struct employee *first = NULL;
	FILE * pFile;
	int i;
	pFile = fopen(filename, "r");
	
	if (pFile != NULL)
	{
		temp = malloc(sizeof(struct employee));

		if (fscanf(pFile, "%s %d %lf %lf", temp->name, &temp->id, &temp->hours, &temp->rate) == 4)
		{
			temp->netInc = 0;
			temp->tax = 0;
			temp->next = first;
			first = temp;
		}	

		for (i = 1; i < MAX_NUM_EMPLOYEES; i++) 
		{
			new = malloc(sizeof(struct employee));

			if (fscanf(pFile, "%s %d %lf %lf", new->name, &new->id, &new->hours, &new->rate) == 4)
			{
				new->netInc = 0;
				new->tax = 0;
				new->next = NULL;
				append(first, new);
			} 	
		}
	}	
	return first;
}

int writeSalaryInfoToFile(struct employee *listHead, char* filename)
{
	struct employee *p;
	FILE * pFile;
	pFile = fopen(filename, "w");
	if (pFile != NULL)
 	{
		for (p = listHead; p != NULL; p = p->next)
			fprintf(pFile, "%s,%d,%.2f,%.2f\n", p->name, p->id, p->netInc, p->tax);
	}
	return 0;
}