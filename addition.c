/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include<stdio.h>
#include "apc.h"


int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist*temp1 = *tail1;
    Dlist*temp2 = *tail2;

    int res=0;
    int carry=0;

    
    while(temp1 != NULL && temp2 !=NULL)
    {
        res = temp1->data + temp2->data + carry;

        carry = res/10;    
	    res  = res % 10;

        insert_at_first(headR,tailR,res);
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    
    while(temp2 != NULL )
    {

		res = temp2->data + carry;
        carry = res / 10;
        res = res % 10;
        insert_at_first(headR,tailR,res);
        temp2 = temp2->prev;
    }

    while(temp1 != NULL )
    {
		res = temp1->data + carry;
		carry = res/10;
		res = res%10;
        insert_at_first(headR,tailR,res);
    	temp1 = temp1->prev;
    }

	if(carry != 0)
	{
		insert_at_first(headR,tailR,carry);
	}
    

	return SUCCESS;
}
