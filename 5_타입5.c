// 4_타입5.c
#include <stdio.h>

// 비트 필드 구조체
// 1. 비트 필드 멤버의 정수 타입이 signed인지 unsigned인지 미지정 동작입니다.
//  => 컴파일러의 구현에 의존합니다.
//   반드시 비트 필드 멤버를 사용할 때, signed / unsigned 명시해야 합니다.

struct s {
    // int a : 8; /* NO!, 미지정 동작 */
    // int b : 8; /* NO!, 미지정 동작 */

    signed int a : 8;
    signed int b : 8;

    unsigned int c : 8;
    unsigned int d : 8;
};

int main(void)
{
}
