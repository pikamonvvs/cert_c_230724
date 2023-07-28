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
int main(void)
{
    int a = 100;
    int b = 200;
    printf("%d\n", a + b); // int

    long la = 100L;
    long lb = 200L;
    printf("%ld\n", la + lb); // long

    return 0;
}
