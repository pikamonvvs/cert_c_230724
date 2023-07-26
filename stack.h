// stack.h
#ifndef PROJ_UTILS_STACK_H
#define PROJ_UTILS_STACK_H

// 전방 선언
struct stack;
#if 0
// 헤더에서 소스로 이동합니다.
struct stack {
    void** arr;
    int top;
    int size;
};
#endif

// 불투명한 타입을 대상으로 typedef와 포인터를 사용할 수 있습니다.
typedef struct stack STACK;

extern void print_stack(const STACK* s);
extern STACK* create_stack(int size);

#endif
