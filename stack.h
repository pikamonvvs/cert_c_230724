// stack.h
#ifndef PROJ_UTILS_STACK_H
#define PROJ_UTILS_STACK_H

struct stack {
    void** arr;
    int top;
    int size;
};

typedef struct stack STACK;

extern void print_stack(const STACK* s);
extern STACK* create_stack(int size);

#endif
