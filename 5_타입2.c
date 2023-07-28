// 타입2.c
#include <stdio.h>

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

int main(void)
{
    char c = 42; // signed / unsigned 인지 미지정 동작입니다.
    int n = 100; // 부호 있는 32비트 정수 타입

    return 0;
}
