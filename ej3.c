#include "stack.h"
#define VERBOSE_MODE FALSE

static Stack stack = {0};

int main(void)
{
	int i=0;
	initialize(&stack, assign_max());
	
	for(i=0; i<=stack.max; i++)
	{
		push(&stack, NULL_ELEMENT, TRUE, VERBOSE_MODE);
	}
	
	print_stack(stack, VERBOSE_MODE);
	reverse_stack(&stack, VERBOSE_MODE);
	print_stack(stack, VERBOSE_MODE);
	
	return SUCCESS;
}