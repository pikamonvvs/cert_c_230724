// 4_타입5.c
#include <stdio.h>

// 비트 필드 구조체
// 1. 비트 필드 멤버의 정수 타입이 signed인지 unsigned인지 미지정 동작입니다.
//  => 컴파일러의 구현에 의존합니다.
//   반드시 비트 필드 멤버를 사용할 때, signed / unsigned 명시해야 합니다.

// 2. 정수 프로모션 규칙이 적용됩니다.

struct s {
    // int a : 8; /* NO!, 미지정 동작 */
    // int b : 8; /* NO!, 미지정 동작 */

    signed int a : 8;
    signed int b : 8;

    // unsigned로 처리되는 경우, int가 모든 값을 포함할 수 있으므로
    // 필드 크기가 int 보다 작은 경우, int로 승격됩니다.
    unsigned int c : 8;
    unsigned int d : 8;
    unsigned int e : 31;
    unsigned int f : 31;

    // 필드 너비가 int와 동일한 경우, unsigned int가 됩니다.
    unsigned int g : 32;
    unsigned int h : 32;

    // signed int flag : 1; /* NO! */
    //  - 1비트만 지정할 경우 반드시 unsigned 이어야 합니다.
};

int main(void)
{
    struct s data = { .a = 10, .b = 20, .c = 30, .d = 40 };

    // data.a + data.b => int
    // data.c + data.d => int
    // data.e + data.f => int
    // data.g + data.h => unsigned int
}
