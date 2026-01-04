/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include "apc.h"

 //puts -1 if sign is negative , 1 if positive
 int sign1 = 0;
 int sign2 = 0;

int main(int argc,char*argv[])
{
    /* Declare the pointers */
    /* Initialize the pointers */
    Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL, *tailR=NULL;
    char option, operator=0;



	/* function for validation and sign */
	if(validate_cla(argc,argv) == 1)
		return 1; 

    /* extract the operator */
	operator = argv[2][0];

	
	/* used for finding the largest */
	char temp1[20];
	char temp2[20];

    /* function to convert CLA to list */
	if(argv[1][0] == '+' || argv[1][0] == '-' )
	{
		digit_to_list(argv[1]+1,&head1,&tail1);
	}
	else
	{
		digit_to_list(argv[1],&head1,&tail1);
	}


	if(argv[3][0] == '+' || argv[3][0] == '-' )
	{
		digit_to_list(argv[3]+1,&head2,&tail2);
	}
	else
	{
		digit_to_list(argv[3],&head2,&tail2);
	}


    switch(operator)
    {
		case '+':
			/* call the function to perform the addition operation */
			if(check_num_is_zero(&head1)==1 && check_num_is_zero(&head2)==1 )
			{
				printf("Result: ");
				printf("0");
				printf("\n");
				break;

			}
			if(sign1 == -1 && sign2 == 1 )
			{
				//-3 + 2
				if(largest_list(head1,head2) > 0)
				{
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					printf("Result: ");
					printf("-");
					print_list(headR);
					printf("\n");
					break;
				}

				//-2 + 3
				if(largest_list(head1,head2) <= 0)
				{
					//interchange h1 and h2 bcz , subtract 3-2
					subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
					printf("Result: ");
					print_list(headR);
					printf("\n");
					break;
				}
				
			}


			if(sign1 == 1 && sign2 == -1 )
			{
				//-3 + 2
				if(largest_list(head1,head2) >= 0)
				{
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					printf("Result: ");
					print_list(headR);
					printf("\n");
					break;
				}

				//-2 + 3
				if(largest_list(head1,head2) < 0)
				{
					//interchange h1 and h2 bcz , subtract 3-2
					subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
					printf("Result: ");
					printf("-");
					print_list(headR);
					printf("\n");
					break;
				}
			}

			if(sign1 == 1 && sign2 == 1)
			{
				addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				printf("Result: ");
				print_list(headR);
				printf("\n");
				break;
			}

			if(sign1 == -1 && sign2 == -1)
			{
			 	addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			 	printf("Result: ");
			 	printf("-");
				print_list(headR);
				printf("\n");
				break;
			}
			
		case '-':

			/* call the function to perform the subtraction operation */
			if(check_num_is_zero(&head1)==1 && check_num_is_zero(&head2)==1 )
			{
				printf("Result: ");
				printf("0");
				printf("\n");
				break;

			}
			if(sign1 == -1 && sign2 == 1)
			{
			
				addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				printf("Result: ");
				printf("-");
				print_list(headR);
				printf("\n");
				break;
			}

			if(sign1 == 1 && sign2 == -1)
			{
				addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				printf("Result: ");
				print_list(headR);
				printf("\n");
				break;
			}

			if(sign1 == 1 && sign2 == 1)
			{
				if(largest_list(head1,head2) < 0)
				{
					subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
					printf("Result: ");
					printf("-");
					print_list(headR);
					printf("\n");
					break;

				}
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					printf("Result: ");
					print_list(headR);
					printf("\n");
					break;
			}
		

			if(sign1 == -1 && sign2 == -1)
			{
				if(largest_list(head1,head2) <= 0)
				{
					subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
					printf("Result: ");
					print_list(headR);
					printf("\n");
					break;

				}
				subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				printf("Result: ");
				printf("-");
				print_list(headR);
				printf("\n");
				break;
			}
			break;
		case 'x':	
			/* call the function to perform the multiplication operation */
			if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
			{
				printf("Result: ");
				if((sign1+sign2)== 0 && (check_num_is_zero(&head1) == 0 || check_num_is_zero(&head1) == 0) )
				{
					printf("-");
				}
				print_list(headR);
				printf("\n");
			}
			break;
		case '/':	
			/* call the function to perform the division operation */
			if(check_num_is_zero(&head2) == 1)
			{
				printf(RED"NOT DEFINED\n"RESET);
				break;
			}
			if(division(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
			{
				printf("Result: ");
				if((sign1+sign2)== 0 && check_num_is_zero(&head1) != 1)
				{
					printf("-");
				}
				print_list(headR);
				printf("\n");
			}
			break;
		default:
			printf("Invalid Input:-( Try again...\n");
    }

	delete_list(&head1,&tail1);
	delete_list(&head2,&tail2);
	delete_list(&headR,&tailR);
    return 0;
}



