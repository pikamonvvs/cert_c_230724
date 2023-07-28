// 타입2.c
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
// 정수 타입이 가지고 있는 한계값 / 최소값

// * char는 문자 타입입니다.
// * C/C++ 에서 char 타입은 3가지 있습니다.
//   char
//   signed char / unsigned char

// * C의 정수 타입
//  - signed char / unsigned char
//  - short / unsigned short
//  - int / unsigned int
//  - long / unsigned long
//  - long long / unsigned long long

#if 0
int main(void)
{
    char c = 42; // signed / unsigned 인지 미지정 동작입니다.
    int n = 100; // 부호 있는 32비트 정수 타입

    return 0;
}
#endif

// * 정수 변환(캐스팅) 규칙에 대해서 이해하는 것이 중요합니다.
//    - 캐스팅
//    1) 암묵적인(implicit) 캐스팅: 다른 타입임에도 캐스팅 연산자를 사용하지 않고도,
//                              변환이 수행됩니다.
//    2) 명시적인(explicit) 캐스팅: 개발자가 캐스팅 연산자를 통해 타입을 변환합니다.

// * 암묵적인 캐스팅이 수행될 경우, 잘못된 연산으로 인해
//   데이터가 손실되거나 잘못 해석될 수 있습니다.

// * 오버플로우(Overflow)
//  - 부호 있는 정수가 자신이 표현할 수 있는 범위를 벗어나는 연산을 수행하였을 때
//  => 미정의 동작

#if 0
int main(void)
{
    int n = INT_MAX;
    int result = n + 1;

    printf("%d\n", result);

    return 0;
}
#endif

// >> 오른쪽 쉬프트
// - 산술 쉬프트(부호 있는 정수): 부호 비트(MSB)
// - 논리 쉬프트(부호 없는 정수): 0

// * 정수 프로모션(Promotion)
// - C/C++ 에서 int 타입보다 작은 타입은 연산이 수행될 때,
//   int 타입 또는 unsigned int 타입으로 암묵적인 변환이 수행됩니다.

#if 0
int main(void)
{
    int8_t a = 0x80; // 1000 0000

    // promotion이 발생할 때, 부호 있는 정수 타입은 부호 비트가 확장됩니다.
    int n1 = a;
    printf("%x\n", n1); // FF FF FF 80

    uint8_t b = 0x80;
    int n2 = b;
    printf("%x\n", n2); // 80

    return 0;
}
#endif

#if 0
int main(void)
{
    uint8_t port = 0x5a;
    // uint8_t result = (~port) >> 4;

    // 해결 방법
    uint8_t result = (uint8_t)(~port) >> 4;

    // * 기대한 것
    //  0x5a: 0101 1010
    // ~0x5a: 1010 0101
    //  >> 4: 0000 1010
    //-------------------
    //        0A

    // * 실제 일어난 일
    //      0x5a:  0000 0000 0000 0000 0000 0000 0000 0101 1010 => int
    //     ~0x5a:  1111 1111 1111 1111 1111 1111 1111 1010 0101 => int
    //      >> 4:  1111 1111 1111 1111 1111 1111 1111 1111 1010
    printf("%x\n", (~port) >> 4); // fffffffa

    // * 해결 방법
    //      0x5a:  0000 0000 0000 0000 0000 0000 0000 0101 1010
    //     ~0x5a:  1111 1111 1111 1111 1111 1111 1111 1010 0101
    // (uint8_t):  1010 0101
    // promotion: 0000 0000 0000 0000 0000 0000 0000 1010 0101
    //      >> 4: 0000 0000 0000 0000 0000 0000 0000 0000 1010

    // 왜 FA라는 결과가 나오는지 생각해보세요.
    printf("%x\n", (uint8_t)(~port) >> 4);

    return 0;
}
#endif
