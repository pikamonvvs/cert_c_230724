// 2_전처리기9.c
#include <stdio.h>

// 예외 4. 매크로 함수에서만 허용되는 문법을 사용할 때
// => 매크로 함수를 코드를 생성하는 기술을 통해 도구로 제공하는 경우가 있습니다.
#define EVAL_BINOP(OP, L, R) ((L)OP(R))

int main(void)
{
    int a = 100;
    int b = 42;

    printf("%d\n", EVAL_BINOP(+, a, b));
    printf("%d\n", EVAL_BINOP(-, a, b));
    printf("%d\n", EVAL_BINOP(*, a, b));

    return 0;
}
