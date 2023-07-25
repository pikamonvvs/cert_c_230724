// 2_전처리기15.c
#include <stdio.h>

// #include "a.h" // 표준에서 제공하는 헤더
#include "complex.h"
// 헤더파일은 include guard를 반드시 작성해야 합니다.
// => 중복 포함의 문제를 해결하기 위해서

#if 0
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

struct complex {
    int real;
    int image;
};

#endif
#endif

// 문제점: 예약어를 사용하고 있습니다.
//  => C/C++ 표준에서는 예약어를 다음과 같이 정의하고 있습니다.
// 1) _(밑줄)로 시작하고, 두번째 문자가 영문자 이거나, 또 다른 밑줄 표시 기호로 시작되는 모든 식별자는 예약어 입니다.
// 2) 밑줄 표시로 시작되는 모든 식별자는 파일 범위에서 일반 식별자와 태그 이름을 위해 예약됩니다.
// _COMPLEX_H_  <- 허용 X
// __Complex_H_ <- 허용 X

static int _global = 10; // <- 허용 X
void _foo(void) { } // <- 허용 X

struct _complex {
    int a;
}; // <- 허용 X

union _u {
    int a;
}; // <- 허용 X

int main(void)
{
    struct complex c;

    // AUTOSAR
    int _local = 10; // 허용 O
}
