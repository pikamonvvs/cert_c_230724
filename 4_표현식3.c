// 4_표현식3.c
#include <stdio.h>
#include <stdlib.h>

// 홀수인지 판단하는 함수 입니다.
#if 0
int is_odd(int n)
{
    return n % 2 == 1;
}
// 문제점: 음수가 전달되었을 때, 결과가 제대로 처리되지 않습니다.
#endif

#if 0
// 해결 방법 1. 절대값
int is_odd(int n)
{
    return abs(n % 2) == 1;
}
#endif

// 1) n % 2 => r
//    n / 2
//    * C는 나머지 / 나누기 연산의 결과의 부호에 대한 정의가 존재하지 않았습니다.
//    => 미지정 동작
// 2) C99 표준에서 정수에 대한 /, % 연산의 결과는 나누는 수(n)의 부호로 결정됩니다.

// 음수를 구하는 방법
// 1) 나머지 연산
// 2) 비트 AND 연산

// 4  => 0000 0100
// 3  => 0000 0011
// 2  => 0000 0010
// 1  => 0000 0001
// 0  => 0000 0000

// 음수(2의 보수법)
//  -42
//   42: 32 + 8 + 2
//       0010 1010
//       1101 0101 + 1
//      -----------
//       1101 0110

// * 우선순위 문제가 있습니다.
//  - C에서 직관적이지 않은 낮은 우선순위를 가지는 연산자로 인해서
//    논리적인 오류가 발생합니다.
//     ==, !=
//     &
//     ^
//      |
//     &&
//     ||
// - 비트 이항 연산자(&,^, |), 논리 연산자(&&, ||)를 사용할 때
//   괄호를 잘 사용해야 합니다.

#if 0
int is_odd(int n)
{
    // return n & 0x1 == 1;
    return (n & 0x1) == 1;
}

int main(void)
{
    printf("%d\n", is_odd(-1));
    printf("%d\n", is_odd(-3));
    printf("%d\n", is_odd(5));
    printf("%d\n", is_odd(7));

    printf("%d\n", is_odd(-2));
    printf("%d\n", is_odd(-4));
    printf("%d\n", is_odd(6));
    printf("%d\n", is_odd(8));

    return 0;
}
#endif

int is_even(int n)
{
    // return n & 0x1 == 0; /* 잘못된 코드 */
    return (n & 0x1) == 0;
}

int main(void)
{
    printf("%d\n", is_even(-1));
    printf("%d\n", is_even(-3));
    printf("%d\n", is_even(5));
    printf("%d\n", is_even(7));

    printf("%d\n", is_even(-2));
    printf("%d\n", is_even(-4));
    printf("%d\n", is_even(6));
    printf("%d\n", is_even(8));

    return 0;
}
