/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist*t1 = *tail1;
	Dlist*t2 = *tail2;
	Dlist*rh = NULL;
	Dlist*rt = NULL;
	Dlist* sumh = NULL;
	Dlist* sumt = NULL;

	int res = 0;
	int borrow = 0;
	int zero_count = 0;

	while(t2 != NULL)
	{
		borrow = 0;
		rh = rt = NULL;
		t1 = *tail1;

		while(t1 != NULL)
		{
			res = ((t2->data) * (t1->data)) + borrow;

			borrow = 0;

			if(res > 9)
			{
				borrow = res/10;
				res = res % 10;
			}

			insert_at_first(&rh,&rt,res);
			t1 = t1->prev;
		}
		

		if(borrow != 0)
		{
			insert_at_first(&rh,&rt,borrow);
		}

		for(int j=0;j<zero_count;j++)
		{
		 	insert_at_last(&rh,&rt,0);
		}

		if(zero_count != 0 )
		{
			addition(headR,tailR,&rh,&rt,&sumh,&sumt);
			delete_list(headR,tailR);
			*headR = sumh;
			*tailR = sumt;
			sumh = NULL;
			sumt = NULL;
		}
		else
		{
			*headR = rh;
			*tailR = rt;
		}

		zero_count++;
		t2 = t2->prev;
	}

	

	return SUCCESS;

}
