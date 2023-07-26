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
//  : 정보 은닉(Information Hiding)

// => C++에서는 pImpl idiom 개념과 유사합니다.
//  : 컴파일 속도를 증가하는 효과도 얻을 수 있습니다.

// => MISRA
//   - Advisory
//   : 불투명한 타입은 정보 은닉을 통해 접근을 제어할 수 있지만,
//     일반적인 형태에 비해 불편함이 있습니다.
//    - 판단이 필요합니다.

// * 단점
// 1) 정적 인라인 함수 사용 불가능합니다.
// 2) 포인터 기반으로 사용해야 하기 때문에, 스택에 메모리를 할당이 불가능합니다.
//    "정적 메모리 또는 동적 메모리 할당"
// 3) 접근 제어로 인해서 번거로움이 발생합니다.

#if 0
struct stack {
    void* a;
    int t;
    int s;
};
#endif

int main(void)
{
    STACK* stack = create_stack(10);

    // STACK s;

    // 잘못된 행위
    // stack->top = 100;
    // stack->size = 50;

    // printf("%d, %d\n", stack->t, stack->s);

    print_stack(stack);

    return 0;
}
