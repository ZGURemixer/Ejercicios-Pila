#include "stack.h"
#define VERBOSE_MODE FALSE

typedef struct Data {
	Element lowest;
	Element highest;
} Data;

Data check_stack(Stack stack, Bool verbose)
{
	Data data = {0};
	Element current;
	
	data.highest = data.lowest = peek(stack, VERBOSE_MODE);
	
	do{
		pop(&stack);
		if((current = peek(stack, VERBOSE_MODE)) >= data.highest)
		{
			data.highest = current;
		}
		if(current <= data.lowest)
		{
			data.lowest = current;
		}
		if(verbose)
		{
			printf("Stack top: %d\n", stack.top);
		}			
	}while(stack.top > FIRST_INDEX);
	
	return data;
}

void print_data(Data data)
{
	printf("Highest: %d\n", data.highest);
	printf("Lowest: %d\n", data.lowest);
}

static Stack stack = {0};
static Data data = {0};

int main(void)
{
	int i=0;
	initialize(&stack, assign_max());
	
	for(i=0; i<=stack.max; i++)
	{
		push(&stack, NULL_ELEMENT, TRUE, VERBOSE_MODE);
	}
	
	print_stack(stack, VERBOSE_MODE);
	data = check_stack(stack, VERBOSE_MODE);
	print_data(data);
	
	return SUCCESS;
}