// 2_전처리기14.c
#include <stdio.h>

#define MORE_ARGS 0

int foo
#if (MORE_ARGS == 1)
    (int a, int b, int c, int d)
#else
    (int a, int b, int c)
#endif
{
#if (MORE_ARGS == 1)
    return a + b + c + d;
#else
    return a + b + c;
#endif
}

#if (MORE_ARGS == 1)
#define CALL_FOO(a, b, c, d) foo(a, b, c, d)
#else
#define CALL_FOO(a, b, c) foo(a, b, c)
#endif

// 매크로 함수의 인자 목록에서 전처리기 지시어에 대한 사용은 미정의 동작입니다.
// => C의 표준 함수가 매크로 함수일 가능성이 있습니다.
//   ex) memcpy, printf, assert ...

#include <string.h>

int main(void)
{
// 미정의 동작
#if 0
    int result = CALL_FOO(10, 20,
#if (MORE_ARGS == 1)
        30,
#endif
        40);
#endif

#if 1
    // 해결 방법
#if (MORE_ARGS == 1)
    int result = CALL_FOO(10, 20, 30, 40);
#else
    int result = CALL_FOO(10, 20, 40);
#endif
#endif

    printf("result: %d\n", result);
}
