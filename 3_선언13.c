// 3_선언13.c
#include <stdio.h>

#include "user.h"

// extern USER current;
// 1. 외부에서 접근하면 안되는 전역 변수와 전역 함수는
//    내부 연결을 가지는 static 사용해야 합니다.
// => 전역 변수
//    : 상태
//    전역 함수
//    : 상태를 조작하는 연산
//   => extern -> public
//      static -> private

// 2. 변수 또는 함수의 가시성을 제한하면
//    실수 또는 악의적인 접근의 위험성을 줄일 수 있습니다.

// 3. 이름 충돌을 문제도 방지할 수 있습니다.
// int current = 100;

// call to undeclared function 'foo'; ISO C99 and later do not support implicit function declarations

// 전역 함수는 선언시 아래 두 개의 방법 모두 상관없습니다.
// - extern void foo(void);
// - void foo(void);
void foo(void);

// 전역 변수 정의
// int global;
// 0000000000000004 C _global

// 전역 변수 선언
extern int global;
//                  U _global

int main(void)
{
    USER* user = get_current_user();
    print_user(user);

    foo();

    // print_user(&current);
    printf("%d\n", global);

    return 0;
}
