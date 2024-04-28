#include "stack.h"
#define VERBOSE_MODE FALSE

void 
to_binary(Element number, Stack *stack)
{
	do {
		push(stack, number % 2, FALSE, VERBOSE_MODE);	
		number = number / 2;	
	} while (number > 0);
	
	reverse_stack(stack, VERBOSE_MODE);
}

void
print_stack_binary(Stack stack)
{
    int i = 0;

    while (stack.array[i] != NULL_ELEMENT) 
	{
        printf("%d", stack.array[i++]);
    }
}

Element 
assign_number(void)
{
	Element number = NULL_ELEMENT;
	
	while (TRUE) {
		printf("Ingrese el numero: ");
		fflush(stdin);
		
		if (scanf("%d", &number) && number > 0)
		{
			return number;
		}
	}
}

static Stack stack = { 0 };

int
main(void)
{
    initialize(&stack, MAX_STACK);
    to_binary(assign_number(), &stack);
    print_stack_binary(stack);
    
    return SUCCESS;
}