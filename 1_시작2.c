// 1_시작2.c

// * C 언어 장점
// 1) C 컴파일러는 많은 프로세서에서 쉽게 사용할 수 있습니다.
//    "이식성"
// 2) C 프로그램은 효율적인 기계어 코드로 컴파일 될 수 있습니다.
// 3) 국제 표준 기구(ISO)에 의해 정의됩니다.

// * C 언어 문제점
//  1) 미정의 동작(Undefined Behavior)
//   - C언어 표준에서 정의되지 않은 동작을 의미합니다.
//     미정의 동작을 수행하는 코드는 컴파일러나 실행 환경에 따라서 예측할 수
//     없는 동작을 보여줄 수 있습니다.
#if 0
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n1 = 5;
    int n2 = 0;

    // int result = n1 / n2; /* 미정의 동작 */

    int x = INT_MAX;
    printf("%d\n", x + 1); /* 미정의 동작 */

    int* p = NULL;
    *p = 42; /* 미정의 동작 */

    return 0;
}
#endif

//  2) 미지정 동작(Unspecified Behavior)
//   - 미지정 동작은 C 표준에서 동작이 여러가지 가능성 중 하나로 정의되지만
//     그중에서 어떤 것이 선택될지 명시되지 않을 것을 의미합니다.
//     컴파일러와 실행환경에 따라서 다른 결과가 발생할 수 있습니다.
#include <stdio.h>

int g = 0;

int f1(void)
{
    g = 100;
    return 2;
}

int f2(void)
{
    g = 200;
    return 1;
}

/*
int main(void)
{
    // 미지정 동작
    // > 이항 연산자에서 함수의 호출이 앞에서부터 수행되는지,
    //   뒤에서부터 수행되는지 미지정 동작입니다.
    int result = f1() + f2();

    // int r1 = f1();
    // int r2 = f2();
    // int result = r1 + r2;

    printf("%d\n", result);

    printf("g: %d\n", g);

    return 0;
}
*/

int foo(int a, int b)
{
    return a + b;
}

int main(void)
{
    // 인자를 전달하는 순서는 미지정 동작입니다.
    // int result = foo(f1(), f2());

    int r1 = f1();
    int r2 = f2();
    int result = foo(r1, r2);

    printf("result: %d\n", result);

    printf("g: %d\n", g);

    int n; // 초기값 - 미지정 동작
    switch (n) {
    case 0:
        break;

    default:
        break;
    }

    return 0;
}
