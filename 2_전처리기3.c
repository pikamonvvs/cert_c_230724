// 2_전처리기3.c
#include <stdio.h>

#if 0
#define SQUARE(x) ((x) * (x))
#define ABS(x) ((x) > 0 ? (x) : -(x))

// 매크로 함수에서 매개 변수가 두 번이상 치환될 경우,
// 그 안에서 부수효과가 발생하면, 미정의 동작이 발생합니다.
// => 매크로 함수를 통해 해당하는 문제를 해결하기 어렵습니다.

int main(void)
{
    int x = 10;
    printf("%d\n", SQUARE(++x));
    // printf("%d\n", ((++x) * (++x))); /* 미정의 동작 */

    int a = -10;
    printf("%d\n", ABS(--a)); /* 미정의 동작 */

    return 0;
}
#endif

// 해결 방법 1.
// 1. 매크로 함수의 매개 변수에 대한 증가와 감소를 매크로 함수 호출 이전에 수행해야 합니다.
// 2. 매개 변수가 2번 이상 치환되는 형태의 매크로 함수를
//    이름을 통해 안전하지 않음을 알리는 것이 좋습니다.
#if 0
#define UNSAFE_SQUARE(x) ((x) * (x))
#define UNSAFE_ABS(x) ((x) > 0 ? (x) : -(x))

int main(void)
{
    int x = 10;
    ++x;
    printf("%d\n", UNSAFE_SQUARE(x));

    int a = -10;
    --a;
    printf("%d\n", UNSAFE_ABS(a));

    return 0;
}
#endif

// 해결 방법 2.
// => C99에서 새롭게 도입된 문법이 있습니다.
//    "inline 함수"
// 1) 인라인 함수는 함수를 호출하지 않고,
//    함수의 본문으로 기계어 치환을 수행합니다.
// 2) 인라인 최적화는 컴파일 최적화 명령입니다.
//    사용자가 inline의 키워드를 지정하여도, 무조건 인라인 치환이 수행되지 않습니다.
//     MSVC: /Ob1
// 핵심: 인라인 함수와 매크로 함수의 의도가 동일하다면,
//      인라인 함수가 선호되어야 합니다.

#define SQUARE(x) ((x) * (x))
static inline int square(int x) { return x * x; }
// 인라인 함수는 반드시 Internal linkage(내부 연결)을 갖도록 만들어져야 합니다.

int main(void)
{
    int x = 10;
    // printf("%d\n", square(++x));

    int result = 0;
    result = square(x);
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR result$[rsp], eax
    */

    result = SQUARE(x);
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR result$[rsp], eax
    */

    return 0;
}
