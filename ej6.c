#include "stack.h"
#define VERBOSE_MODE FALSE

void
remove_lowest_value(Stack* stack)
{
    int i, lowest_position = find_first_non_null(*stack, VERBOSE_MODE);
    Element current = NULL_ELEMENT;
    static Stack backup = { 0 };
    backup = *stack;
    initialize(stack, backup.max + 1);

    for (i = 0; i <= backup.max; i++) {
        if (backup.array[i] != NULL_ELEMENT &&
            backup.array[i] <= backup.array[lowest_position]) {
            lowest_position = i;
        }
    }

    backup.array[lowest_position] = NULL_ELEMENT;

    do {
        if ((current = peek(backup, VERBOSE_MODE)) != NULL_ELEMENT) {
            push(stack, current, FALSE, VERBOSE_MODE);
        }
        pop(&backup);
    } while (backup.top >= FIRST_INDEX);
}

static Stack stack = { 0 };

int
main(void)
{
    int i;
    initialize(&stack, assign_max());

    for (i = 0; i <= stack.max; i++) {
        push(&stack, NULL_ELEMENT, TRUE, VERBOSE_MODE);
    }

    print_stack(stack, VERBOSE_MODE);
    remove_lowest_value(&stack);
    reverse_stack(&stack, VERBOSE_MODE);
    print_stack(stack, VERBOSE_MODE);
    return SUCCESS;
}