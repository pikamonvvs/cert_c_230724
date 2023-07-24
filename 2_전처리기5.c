// 2_전처리기5.c
#if 0
#include <stdio.h>

int operations = 0; /* 전체 함수 호출 횟수 */
int calls_to_f = 0; /* F() 함수 호출 횟수 */
int calls_to_g = 0; /* G() 함수 호출 횟수 */

// 매크로 함수가 결과를 제공할 때
#define F(x) (++operations, ++calls_to_f, 2 * (x))
#define G(x) (++operations, ++calls_to_g, (x) + 1)

// 문제점
// 1) 동일한 지역변수가 제공될 경우, 문제가 발생합니다.
// 2) 미정의 동작
int main(void)
{
    // , - 나열 연산자
    printf("%d\n", (1, 2, 3)); // 3

    int result;
    int x = 10;

    result = F(x) + G(x); /* 미정의 동작 */
    // result = (++operations, ++calls_to_f, 2 * (x)) + (++operations, ++calls_to_g, (x) + 1);

    printf("result: %d\n", result);
    printf("%d %d %d\n", operations, calls_to_f, calls_to_g);

    return 0;
}
#endif

// 아래 코드를 인라인 함수를 통해 변경해보세요.
#include <stdio.h>

int operations = 0; /* 전체 함수 호출 횟수 */
int calls_to_f = 0; /* f() 함수 호출 횟수 */
int calls_to_g = 0; /* g() 함수 호출 횟수 */

static inline int f(int x)
{
    ++operations;
    ++calls_to_f;

    return 2 * x;
}

static inline int g(int x)
{
    ++operations;
    ++calls_to_g;

    return x + 1;
}

int main(void)
{
    // , - 나열 연산자
    // printf("%d\n", (1, 2, 3)); // 3

    int result;
    int x = 10;

    // 이항 연산자 안에서 함수의 호출을 사용하는 것은
    // 순서가 미지정 동작입니다.
    // result = f(x) + g(x);

    int rf = f(x);
    int rg = g(x);
    result = rf + rg;

    printf("result: %d\n", result);
    printf("%d %d %d\n", operations, calls_to_f, calls_to_g);

    return 0;
}
