// 3_선언12.c
#include <stdio.h>

// 스택을 만들어봅시다.
#include "stack.h"

int main(void)
{
    STACK* stack = create_stack(10);

    print_stack(stack);

    return 0;
}
