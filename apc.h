#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#define RED   "\033[1;31m"
#define RESET "\033[0m"

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* DLL functions */
int insert_at_last(Dlist**head , Dlist**tail,int data);
int insert_at_first(Dlist**head , Dlist**tail,int data);
int delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist* head);

/* to find the largest number */
int largest_list(Dlist* head1,Dlist* head2);

/* to convert a string to list */
void digit_to_list(char*op , Dlist**head , Dlist**tail);

/* function to check if the number is 0 */
int check_num_is_zero(Dlist** head);

/* to validate the the input and find the signs of each number */
int validate_cla(int argc,char*argv[]);

#endif
