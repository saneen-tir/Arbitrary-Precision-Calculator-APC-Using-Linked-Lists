/*******************************************************************************************************************************************************************
*Title			: Division
*Description	: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters : head1: Pointer to the first node of the first double linked list.
				: tail1: Pointer to the last node of the first double linked list.
				: head2: Pointer to the first node of the second double linked list.
				: tail2: Pointer to the last node of the second double linked list.
				: headR: Pointer to the first node of the resultant double linked list.
				: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include<stdio.h>

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	
	Dlist* firsth = NULL;
	Dlist* firstt = NULL;

	Dlist* temp1 = *head1;

	Dlist* temp2h = *head2;
	Dlist* temp2t = *tail2;
	

	Dlist* secondh = NULL;
	Dlist* secondt = NULL;
	int count = 0;


	while(temp1 != NULL)
	{
		count = 0;
		insert_at_last(&firsth,&firstt,temp1->data);
		temp2h = *head2;
	    temp2t = *tail2;
		while(largest_list(firsth,temp2h) >= 0)
		{
			secondh = NULL;
    		secondt = NULL;
			subtraction(&firsth,&firstt,&temp2h,&temp2t,&secondh,&secondt);
			delete_list(&firsth,&firstt);
			firsth = secondh;
			firstt = secondt;
			count++;
			temp2h = *head2;
	        temp2t = *tail2;
		}
		insert_at_last(headR,tailR,count);
		temp1 = temp1->next;
	}
	return SUCCESS;
}
