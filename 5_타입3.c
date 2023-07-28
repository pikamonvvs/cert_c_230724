// 5_타입3.c
#include <stdio.h>

// * 정수 변환 규칙
// 1) 정수 타입 순위(Rank)
//  - long long > long > int > short > signed char
//  - unsinged long long > unsinged long > unsinged int > unsigned short > unsigned char

// 2) 산술 변환 규칙
// => 산술 연산을 수행하기 전에 피연산자의 타입을 변환하고 연산이 수행됩니다.
//  "이항 연산의 경우 두개의 피 연산자가 동일한 타입으로 변환됩니다."

// 1) 같은 타입이면 변환하지 않습니다.
//  예외) 프로모션: int보다 작은 타입의 경우,
//              프로모션 후 수행됩니다.
#if 0
int main(void)
{
    int8_t c1 = 10;
    int8_t c2 = 20;
    printf("%d\n", c1 + c2); // promotion => int

    int a = 100;
    int b = 200;
    printf("%d\n", a + b); // int

    long la = 100L;
    long lb = 200L;
    printf("%ld\n", la + lb); // long

    return 0;
}
#endif

// 2) 두 개의 피연산자가 정수 타입이면, 범위가 큰 타입으로 변환됩니다.
#if 0
int main(void)
{
    int a = 10;
    long la = 100L;

    printf("%ld\n", a + la); // long

    long lb = 10000L;
    long long llb = 2000000LL;
    printf("%ld\n", lb + llb);

    return 0;
}
#endif

// 3) 부호 없는 정수 타입의 피연산자가 다른 피연산자의 순위보다 크거나 같은 경우
//    부호 있는 정수 타입의 피연산자는 부호 없는 정수 타입으로 변환됩니다.
#if 0
int main(void)
{
    unsigned int ua = 10U;
    int a = 100;
    printf("%u\n", ua + a); // unsigned int

    unsigned long lb = 100L;
    int b = 10000;
    printf("%lu\n", lb + b); // unsigned long

    return 0;
}
#endif

// 4) 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을
//    표현할 수 있는 경우, 부호 없는 정수 타입의 피연산자는
//    부호 있는 정수 타입으로 변환됩니다.
#if 0
int main(void)
{
    long long a = 10LL;
    unsigned int ua = 11000U;
    printf("%lld\n", a + ua); // long long

    return 0;
}
#endif

// 5) 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을
//    표현할 수 없는 경우, 부호 있는 정수 타입의 피연산자가 동일 타입의
//    부호 없는 타입으로 두 피연산자 모두 변환됩니다.
int main(void)
{
    // 둘다 8바이트 입니다.
    long long lla = 1000LL;
    unsigned long la = 10000L;

    printf("%llu\n", lla + la);

    return 0;
}
