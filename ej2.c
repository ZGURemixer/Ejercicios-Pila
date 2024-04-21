#include "stack.h"
#define VERBOSE_MODE FALSE

void
reorder_stack(Stack* stack)
{
    int i, lowest_position = 0;
    static Stack backup = { 0 };
    backup = *stack;

    initialize(stack, backup.max + 1);

    do {
        lowest_position = find_first_non_null(backup, VERBOSE_MODE);
        for (i = 0; i <= backup.top; i++) {
            if (backup.array[i] != NULL_ELEMENT &&
                backup.array[i] < backup.array[lowest_position]) {
                lowest_position = i;
            }
        }
        push(stack, backup.array[lowest_position], FALSE, VERBOSE_MODE);
        backup.array[lowest_position] = NULL_ELEMENT;
    } while (backup.top != stack->top);

    if (VERBOSE_MODE) {
        printf("Stack has been re-ordered successfully.\n");
    }
}

static Stack stack = { 0 };

int
main(void)
{
    int i = 0;
    initialize(&stack, assign_max());

    for (i = 0; i <= stack.max; i++) {
        push(&stack, NULL_ELEMENT, TRUE, VERBOSE_MODE);
    }

    print_stack(stack, VERBOSE_MODE);
    reorder_stack(&stack);
    print_stack(stack, VERBOSE_MODE);

    return SUCCESS;
}