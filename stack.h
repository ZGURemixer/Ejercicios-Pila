#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE -1
#define MAX_STACK 100
#define MIN_STACK 1
#define NULL_ELEMENT -42069
#define EMPTY -1
#define FIRST_INDEX 0

typedef short unsigned int Bool;
typedef int Element;

typedef struct Stack {
	Element array[MAX_STACK];
	int top;
	int max;
} Stack;

Element assign_element(int id)
{
	Element element = NULL_ELEMENT;
	
	do{
		printf("Insert element %d: ", id+1);
		fflush(stdin);
	}while(!scanf("%d", &element) || element == NULL_ELEMENT);
	
	return element;
}

void initialize(Stack *stack, int max)
{
	int i;
	
	if(max <= MIN_STACK || max > MAX_STACK)
	{
		fprintf(stderr, "Error: Invalid value assigned to stack.\n");
		exit(FAILURE);
	} else {
		stack->max = --max;
		stack->top = EMPTY;
		
		for(i=0; i<=stack->max; i++)
		{
			stack->array[i] = NULL_ELEMENT;
		}
	}
}

void push(Stack *stack, Element element, Bool user, Bool verbose)
{
	if(stack->top == stack->max)
	{
		fprintf(stderr, "Error: Overflow\n");
		exit(FAILURE);
	} else {
		if(element != NULL_ELEMENT)
		{
			if(verbose)
			{
				printf("Element [%d] should be pushed.\n", element);
			}
			stack->array[++stack->top] = element;
		} else {
			if(user)
			{
				++stack->top;
				stack->array[stack->top] = assign_element(stack->top);
			} else {
				fprintf(stderr, "Error: Invalid value assigned to stack.\n");
				exit(FAILURE);				
			}
		}
	}
}

void pop(Stack *stack)
{
	if(stack->top == EMPTY)
	{
		fprintf(stderr, "Error: Underflow\n");
		exit(FAILURE);
	} else {
		stack->array[stack->top--] = NULL_ELEMENT;
	}
}

Bool is_empty(Stack stack)
{
	return stack.top <= -1;
}

Bool is_full(Stack stack)
{
	return stack.top == stack.max;
}

Element peek(Stack stack, Bool verbose)
{
	if(verbose){
		printf("Top element should be [%d].\n", stack.array[stack.top]);
	}
	return stack.array[stack.top];
}

void print_stack(Stack stack, Bool verbose)
{
	int i;
	
	for(i=0; i<=stack.max; i++)
	{
		if(stack.array[i] != NULL_ELEMENT)
		{
			printf("[%d]", stack.array[i]);
		} else {
			printf("[ ]");
		}
	}
	
	printf("\n");
	
	if(verbose)
	{
		printf("Max: %d\n", stack.max);
		printf("Top: %d\n", stack.top);
	}
}

int assign_max(void)
{
	int max;
	
	do {
		printf("Insert stack size: ");
		fflush(stdin);
	} while (!scanf("%d", &max) || max<=MIN_STACK || max>MAX_STACK);
	
	return max;
}

int find_first_non_null(Stack stack, Bool verbose)
{
	int i;
	
	for(i=0; i<=stack.top; i++)
	{
		if(verbose)
		{
			printf("Checked: [%d]\n", stack.array[i]);
		}
		if(stack.array[i]!=NULL_ELEMENT)
		{
			return i;
		}
	}
	
	fprintf(stderr, "Error: Invalid stack.\n");
	exit(FAILURE);
	return FAILURE;
}

void reverse_stack(Stack *stack, Bool verbose)
{
	static Stack backup = {0};
	backup = *stack;
	
	initialize(stack, backup.max+1);
	
	do{
		push(stack, peek(backup, verbose), FALSE, verbose);
		pop(&backup);		
	}while(backup.top >= FIRST_INDEX);
	
	if(verbose)
	{
		printf("Stack has been reversed successfully.\n");
	}
}