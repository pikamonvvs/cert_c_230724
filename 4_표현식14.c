// 4_표현식14.c
#include <stdio.h>

#if 0
struct X {
    char a[8];
    int n;
};

struct X foo(void)
{
    struct X result = { .a = "Hello", .n = 42 };
    return result;
}

// 1. C99 표준 이전에 함수의 결과로 반환되는 구조체를 바로 접근하는 행위는
//    미정의 동작입니다.

// 2. 함수로 반환되는 구조체의 결과(배열)의 값을 바로 수정하면,
//    미정의 동작입니다.

int main(void)
{
    printf("%d\n", foo().n); /* C90: 미정의 동작, C99: OK */

    // foo().n = 100; /* 컴파일 오류 */
    foo().a[0] = 'X'; /* 미정의 동작 */

    return 0;
}
#endif

#if 0
struct X {
    int a[6];
};

struct X foo(void)
{
    struct X result = { .a = { 1, 2, 3, 4, 5, 6 } };
    return result;
}

int main(void)
{
    // foo();
    // => 함수의 결과를 전달하기 위해, 임시적으로 메모리를 생성해서 복사를 수행합니다.
    //    임시 메모리는 함수가 종료하면 사라집니다.

    printf("%d\n", ++(foo().a[0])); /* 미정의 동작 */

    return 0;
}
#endif

#include <string.h>

struct X {
    int a[6];
};

// 구조체를 값으로 반환하는 것은, 복사의 오버헤드가 있습니다.
// => 사용자 정의 타입은 반환값을 전달하기 위해, 임시 수명을 가지는 메모리에 복사를 해서 전달을 수행합니다.
// => Out Parameter

struct X foo(void)
{
    struct X result = { .a = { 1, 2, 3, 4, 5, 6 } };
    return result; // 1) result -> 임시 메모리 복사
}

// 해결 방법 2. Out Parameter
void goo(struct X* result)
{
    int data[6] = { 1, 2, 3, 4, 5, 6 };
    memcpy(result->a, data, sizeof(result->a));
}

int add(int a, int b) { return a + b; } // 기본 타입은 임시 메모리의 복사로 반환이 전달되지 않습니다.

int main(void)
{
    // 해결 방법 1. 함수의 결과를 변수에 복사해서 사용해야 합니다.
    struct X result = foo(); // 2) 임시 메모리 -> result 변수로 복사

    goo(&result); // !!!

    printf("%d\n", ++(result.a[0]));

    return 0;
}
