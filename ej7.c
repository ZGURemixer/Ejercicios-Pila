#include "stack.h"
#define VERBOSE_MODE FALSE

int
assign_index(Stack* stack)
{
    int index;

    do {
        printf("Enter the 'K' index: ");
        fflush(stdin);
    } while (!scanf("%d", &index) || index <= 0 || index > stack->max + 1);

    return index;
}

void
reorder_stack(Stack stack, int index)
{
    int i, highest_position = 0;
    static Stack backup = { 0 };
    backup = stack;

    initialize(&stack, backup.max + 1);

    do {
        highest_position = find_first_non_null(backup, VERBOSE_MODE);
        for (i = 0; i <= backup.top; i++) {
            if (backup.array[i] != NULL_ELEMENT &&
                backup.array[i] > backup.array[highest_position]) {
                highest_position = i;
            }
        }
        push(&stack, backup.array[highest_position], FALSE, VERBOSE_MODE);
        backup.array[highest_position] = NULL_ELEMENT;
    } while (backup.top != stack.top);

    if (VERBOSE_MODE) {
        printf("Stack has been re-ordered successfully.\n");
    }

    printf("Highest: %d\n", stack.array[FIRST_INDEX]);
    printf("K-est: %d\n", stack.array[--index]);
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
    reorder_stack(stack, assign_index(&stack));
    return SUCCESS;
}