#include "stack.h"
#define VERBOSE_MODE FALSE

float
get_sum(Stack stack)
{
    Element sum = 0;

    do {
        sum += peek(stack, FALSE);
        pop(&stack);
    } while (stack.top > EMPTY);

    return sum;
}

static Stack stack = { 0 };

int
main(void)
{
    int i = 0;
    float average = 0;
    initialize(&stack, assign_max());

    for (i = 0; i <= stack.max; i++) {
        push(&stack, NULL_ELEMENT, TRUE, VERBOSE_MODE);
    }

    print_stack(stack, VERBOSE_MODE);
    printf("Average: %.1f", average = get_sum(stack) / (float)(stack.top + 1));
    return SUCCESS;
}