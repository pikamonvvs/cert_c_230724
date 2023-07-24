// 2_전처리기7.c
#include <stdio.h>

// 예외 2. 조건부 컴파일
// gcc 2_전처리기7.c -DDEBUG_MODE

// 가변인자 매크로(Variadic Macro) => C99
#ifdef DEBUG_MODE
#define TRACE(...) fprintf(stderr, __VA_ARGS__)
#else
#define TRACE(...) (void)0
#endif

// 문제점
// => DEBUG_MODE가 정의되어 있지 않을 때,
//    세미콜론을 누락해도 컴파일 오류가 발생하지 않습니다.
//   : (void)0
//   -> 컴파일 될 때, 아무것도 생성되지 않습니다.

int foo(void)
{
    return 0;
}

int main(void)
{
    // foo();
    // 함수의 결과를 무시하면 안됩니다.

    (void)foo();
    // => 함수의 결과를 무시한다.

    TRACE("hello\n");

    int n = 42;
    double d = 3.14;
    TRACE("%d %lf\n", n, d);

    return 0;
}
