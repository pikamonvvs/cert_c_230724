// 5_타입10.c
#include <stdio.h>
#include <limits.h>

// 비트 연산자(&, |, ^, ~, >>, <<)
// 1) 비트 연산을 signed 타입에 대해서 사용하는 것은 미지정 동작입니다.
//  => 컴파일러의 구현마다 다른 동작의 가능성이 존재한다.
//  => 비트 연산의 대상 타입은 unsigned를 사용해야 합니다.

// 2) >> 쉬프트
//  부호 있는 타입: 부호 비트로 채워집니다. => 산술 쉬프트
//  부호 없는 타입: 0으로 채워집니다.    => 논리 쉬프트

// 3) 쉬프트 연산(>>, <<)
// - 음수 또는 대상체의 비트수 이상으로 쉬프트를 수행하는 것은
//   미정의 동작입니다.

#define BITS(x) (sizeof(x) * CHAR_BIT)

int main(void)
{
    int a = 0xABABABAB; // 1010 1011
    printf("%X\n", a >> 24); // 산술 쉬프트
    printf("%X\n", (a >> 24) & 0xFF);

    printf("%X\n", (unsigned int)a >> 24); // 논리 쉬프트

#if 0
    int shift;
    shift = 33;
    printf("%X\n", a << shift); /* 미정의 동작 */
    shift = -1
    printf("%X\n", a << shift); /* 미정의 동작 */
#endif

    size_t shift;
    shift = 33;
    if (shift <= BITS(a)) { // 쉬프트 연산전 확인이 필요합니다.
        printf("%X\n", a << shift);
    }

    shift = -1;
    if (shift <= BITS(a)) {
        printf("%X\n", a << shift);
    }

    return 0;
}
