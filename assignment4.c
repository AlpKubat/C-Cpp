#include<stdio.h>
#include<stdlib.h>

struct node {
	char letter;
	struct node* next;
};

struct node* head = NULL;

struct node* stack_create(); // creates node pointer.
void stack_push(char l); // pushing to the top a node that its letter is taken.
char stack_pop(); // returning top node's letter and remove it.
char stack_top(); // returning node's letter that at the top. 
int stack_isempty(); // returning 0 if stack is empty, returning 1 at otherwise.
void print_stack(); // removing all node's top to bottom and printing them.


// printing reverse of taken string that taken by arguments.
void main(int argc, char **argv)
{
	
	
	int i = 0; // to travel in the string with pointer
	
	// variable and pointers to push chars to stack.
	char c ; 
	char *string = argv[1];
	
	// traveling in string with pointer to push chars to the stack
	for(c = *(string+i); c != 0; c = *(string+i))
	{
		
		stack_push(c);
		i++;
	}
	
	// printing reverse of string.
	print_stack();
	printf("\n");
	
	
}

// creates node pointer.
struct node* stack_create()
{
	struct node* head = NULL;
	return head;
}

// pushing to the top a node that its letter is taken.
void stack_push(char l)
{
	// creating new node to push stack. 
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->letter = l; // new node's letter is taken by parameter.
	
	// if malloc cant allocate space, printing "overflow".
	if (newNode == NULL)
	{
		printf("\noverflow!!\n");
		return;
	}
	// newNode's next points to top/head.
	newNode->next = head;
	// top node becomes new node.
	head  = newNode;
}

// returning top node's letter and remove it.
char stack_pop()
{
	// if stack is empty printing "underflow!" and returning empty char.
	if (stack_isempty() == 0)
	{
		printf("underflow!");
		return ' ';
	}
	// storing top node's letter for return.
	char topLetter = stack_top();
	
	// creating pointer to delete the top node.
	struct node* delete = head;
	
	// advance head pointer to new top node.
	head = head->next;
	
	// delete top node from ram.
	free(delete);
	
	// returning top letter.
	return topLetter;
}

// returning 0 if stack is empty, returning 1 at otherwise.
int stack_isempty()
{
	// if stack is empty return 0.
	if(head == NULL)
	{
	return 0;
	}
	// if stack is not empty return 1.
	return 1;
}	

// returning node's letter that at the top. 
char stack_top()
{
	// return top node's letter.
	return head->letter;
}

// removing all node's top to bottom and printing them.
void print_stack()
{
	// print and pop all node's that been in stack and pop them.
	while(stack_isempty() == 1)
	{
		printf("%c",stack_top());
		stack_pop();
	}
}


