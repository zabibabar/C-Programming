#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "employee.h"

//Add the struct 'emp' to the end of the linked list pointed to
//by 'listHead' (the first node in the list)
//return a pointer to the first node in the list (listHead)
struct employee* append(struct employee* listHead, struct employee* emp)
{
	struct employee *temp;
	temp = listHead;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	
	temp->next = emp;

	return listHead;
}

//Search for an employee in the list who has the name 'name'
//if found, return a pointer to the employee struct
//otherwise return NULL
struct employee* search(struct employee* listHead, char* name)
{
	 struct employee *p;
	
	  for (p = listHead; p != NULL; p = p->next)
	    if (strcmp(p->name, name) == 0)
	      return p;
	  return NULL;
}

//delete all nodes in the list. This means freeing memory
void clearList(struct employee* listHead)
{
	struct employee *p;
	while(listHead != NULL)
	{
		p = listHead;
		listHead = listHead->next;
		if( p!= NULL)
		    free(p);
	}
}
