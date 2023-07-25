// 3_선언8.c
#include <stdio.h>

// 1. 동일한 가시성을 가지는 식별자는
//    타입포그라피적으로 이름이 모호하지 않아야 한다.
#if 0
int main(void)
{
    int id_I;
    int id_l;
    int id_1;

    int id_Z;
    int id_2;

    int id_0;
    int id_O;

    int id_8;
    int id_B;

    int id_m;
    int id_rn;

    return 0;
}
#endif

void foo(void) { } // OK!
// void goo() { }
// 컴파일 타임에 인자를 체크하지 않습니다.

// C++은
//  foo(void) 와 foo()가 동일합니다.

// int add();
int add(int a, int b);

// K&R Style => 사용하면 안됩니다.
int sub(a, b)
int a, b;
{
    return a - b;
}

int main(void)
{
    printf("%d\n", sub(100, 20));

    // foo(10);
    // goo(10);

    printf("%d\n", add(10, 20));
    // 함수의 인자가 선언된 것보다 적거나 많이 전달되는 것은
    // 미정의 동작입니다.

    // int (*fp1)(void) = &foo;
    // int (*fp2)() = &foo;

    // fp1(100);
    // fp2(100, 200);

    return 0;
}

int add(int a, int b) { return a + b; }
