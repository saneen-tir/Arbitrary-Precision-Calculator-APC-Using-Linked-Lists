/****************************************************************************************************
 * Title           : Support Functions
 * Description     : This file contains helper functions used across the APC (Arbitrary Precision 
 *                   Calculator) project.
 ****************************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include "apc.h"

int extern sign1;
int extern sign2;

int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist* new = malloc(sizeof(Dlist));
    new -> prev = NULL;
    new -> data = data;
    new -> next = NULL;
    
    if(*head == NULL && *tail == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }
    else
    {
        new -> prev = *tail;
        (*tail) -> next = new;
        *tail = new;
        return SUCCESS;
    }
}

/* returns 1 if the num is 0*/
int check_num_is_zero(Dlist** head)
{
	Dlist* temp1 = *head;
	while(temp1 != NULL)
	{
		if(temp1->data != 0)
		{	
			break;
		}
		temp1 = temp1->next;
	}

	if(temp1 == NULL)
		return 1;
	else
		return 0;	
}




int insert_at_first(Dlist**head , Dlist**tail,int data)
{
    Dlist* new = malloc(sizeof(Dlist));
    new->data = data;
    new->prev = NULL;

    if(*head == NULL && *tail == NULL)
    {
        new->next = NULL;
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        return SUCCESS;
    }
}



int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL && *tail == NULL)
        return FAILURE;
    
    Dlist*temp = *head;
    Dlist* prev = NULL;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}



void print_list(Dlist* head)
{
	int flag = 0;
    Dlist* temp = head;
    while(temp !=  NULL)
    {
		if(temp->data != 0)
			flag = 1;
		
		if(flag == 1)
		{
			printf("%d",temp->data);
		}	
        
        temp = temp->next;
    }
	if(flag == 0)
		printf("%d",0);
}


int validate_cla(int argc,char*argv[])
{
	if(argc != 4)
	{
		printf(RED"ERROR :"RESET"Invalid number of command line arguments\n");
		printf("Usage: ./a.out <number1> <operator> <number2>\n");
		return 1;
	}

	int i=0;
	while(argv[1][i])
	{
		if( !strchr("0123456789",argv[1][i]) && !strchr("+-",argv[1][i]))
		{
			printf(RED"ERROR :"RESET"Invalid argument : number1 should only contain +/- and digits\n");
			return 1;
		}
		i++;
	}

	if(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/')
	{
		printf(RED"ERROR: "RESET"Invalid operator , allowed operators are '+' '-' '/' or 'x'\n" );
		return 1;
	}

	i=0;
	while(argv[3][i])
	{
		if( !strchr("0123456789",argv[3][i]) && !strchr("+-",argv[3][i]))
		{
			printf(RED"ERROR :"RESET"Invalid argument , number2 should only contain +/- and digits\n");
			return 1;
		}
		i++;
	}


	if(argv[1][0] == '-')
	{
		sign1 = -1;	
	}
	else if(argv[1][0] == '+')
	{
		sign1 = 1;	
	}
	else
	{
		sign1 = 1;	
	}	
	
	

	if(argv[3][0] == '-')
	{
		sign2 = -1;	
	}
	else if(argv[3][0] == '+')
	{
		sign2 = 1;	
	}
	else
	{
		sign2 = 1;	
	}		

		
}


//returns 1 if list1>list2 , -1 if list1<list2 & 0 if list1==list2
int largest_list(Dlist* head1,Dlist* head2)
{
	Dlist* temp1 = head1;
	Dlist* temp2 = head2;

	Dlist* first_digit1 = NULL;
	Dlist* first_digit2 = NULL;

	int len1 = 0;
	int len2 = 0;

	/* functions to skip leading zeroes */
	while(temp1->data == 0 && temp1 && temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	first_digit1 = temp1;

	while(temp2->data == 0 && temp2 && temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	first_digit2 = temp2;

	/* if the list contains all zeroes */
	if(temp1 == NULL && temp2 == NULL)
		return 0;

	/* check the length of list 1 */
	while(temp1 != NULL)
	{
		len1++;		
		temp1 = temp1->next;	
	}

	/* check the length of list 2 */
	while(temp2 != NULL)
	{
		len2++;		
		temp2 = temp2->next;	
	}

	if(len1>len2)
		return 1;

	if(len1<len2)
		return -1;	

	while(first_digit1 != NULL && first_digit2 != NULL)
	{
		if((first_digit1->data) > (first_digit2->data))
			return 1;
		if((first_digit1->data) < (first_digit2->data))
			return -1;	

		first_digit1 = first_digit1 -> next;
		first_digit2 = first_digit2 -> next;	
	}

	if(first_digit1 == NULL && first_digit2 == NULL)
		return 0;
}

void digit_to_list(char*op , Dlist**head , Dlist**tail)
{
    int i=0;
    while(op[i])
    {
        insert_at_last(head,tail,op[i]-'0');
        i++;
    }
}