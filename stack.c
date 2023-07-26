// stack.c
#include "stack.h"

struct stack {
    void** arr;
    int top;
    int size;
};

#include <stdio.h>
#include <stdlib.h>

void print_stack(const STACK* s)
{
    printf("top=%d, size=%d\n", s->top, s->size);
}

STACK* create_stack(int size)
{
    STACK* stack = malloc(sizeof(STACK));
    if (stack == NULL) {
        return NULL;
    }

    stack->arr = malloc(sizeof(void*) * size);
    if (stack->arr == NULL) {
        free(stack);
        return NULL;
    }

    stack->size = size;
    return stack;
}
