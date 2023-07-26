// 3_선언12.c
#include <stdio.h>

// 스택을 만들어봅시다.
#include "stack.h"

// [문제점]
// 1. 구조체의 구현이 헤더를 통해서 드러납니다.
// 2. 구조체의 멤버의 속성은 함수를 통해 수정되거나 접근되어야 합니다.
// 3. 외부에서 구조체의 데이터를 쉽게 수정할 수 있습니다.

// [해결 방법]
// => 구조체를 불투명한 타입(Opaque Type)을 통해 제공하면,
//    외부에서의 접근을 제어할 수 있습니다.

int main(void)
{
    STACK* stack = create_stack(10);

    // 잘못된 행위
    // stack->top = 100;
    // stack->size = 50;

    print_stack(stack);

    return 0;
}
