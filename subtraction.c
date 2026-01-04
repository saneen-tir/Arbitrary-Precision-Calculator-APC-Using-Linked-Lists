/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description	: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
				: tail1: Pointer to the last node of the first double linked list.
				: head2: Pointer to the first node of the second double linked list.
				: tail2: Pointer to the last node of the second double linked list.
				: headR: Pointer to the first node of the resultant double linked list.
				: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include<stdio.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist*temp1 = *tail1;
    Dlist*temp2 = *tail2;
	int borrow = 0;
	int res = 0;

	while(temp1 != NULL && temp2!=NULL)
	{
		//this works only if there is a borrow & the number is 0
		while(borrow == 1 && temp1->data == 0 && temp2 != NULL)
		{
			insert_at_first(headR,tailR,9-(temp2->data));
			temp1= temp1->prev;
			temp2 = temp2->prev;
		}

		//after the above loop temp2 may be NULL
		if (temp2 == NULL)
		{
			// No more digits in second number  treat them as zero
			res = temp1->data - borrow;
			borrow = 0;
			if (res < 0)
			{
				res = res + 10;
				borrow = 1;
			}
			insert_at_first(headR, tailR, res);
			temp1 = temp1->prev;
			continue;
		}


		//normal subtraction , subtract borrow if present
		res = (temp1->data - borrow) - (temp2->data);
		borrow = 0;

		//if the first no. is lesser than second , we add ten to the first number
		if(res < 0)
		{
			res = ((temp1->data + 10) - (temp2->data));
			borrow = 1;
		}

		insert_at_first(headR,tailR,res);
		temp1 = temp1->prev;
        temp2 = temp2->prev;
	}

	/* this works only if the 2nd num has lesser digits */
	while(temp1 != NULL )
	{
			if(temp1->data == 0 && borrow == 1)
			{
				while(temp1)
				{
					if(temp1->data != 0)
						break;
					insert_at_first(headR,tailR,9);
					temp1 = temp1->prev;
				}
			}
            insert_at_first(headR,tailR,(temp1->data - borrow));
            borrow = 0;
            temp1 = temp1->prev;
    }

}

