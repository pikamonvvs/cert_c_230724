// 3_선언11.c
#include <stdio.h>

// typedef를 이용해서, 구조체 타입을 편리하게 사용할 수 있습니다.
#if 0
struct obj {
    int i;
    float f;
};

typedef struct obj OBJECT;
typedef struct obj* POBJECT;
#endif

#if 0
typedef struct obj {
    int i;
    float f;
} OBJECT, *POBJECT;

// const POBJECT
// => const struct obj* [X]
// => struct obj* const [O]
// 문제점: 포인터를 typedef 한 경우, const가 의도한대로 동작하지 않을 수 있습니다.

void print_obj(const POBJECT obj)
{
    printf("%d, %f\n", obj->i, obj->f);

    // obj = NULL; => ERROR

    // obj->i = 42; => OK
    // obj->f = 10.5; => OK
}

int main(void)
{
    OBJECT obj = { 10, 3.14 };
    print_obj(&obj);

    return 0;
}
#endif

#if 0
// 해결 방법 1. 포인터에 대한 typedef를 사용하지 말자.
//            포인터가 아닌 타입에 대해서 사용하는 것이 좋습니다.
typedef struct obj {
    int i;
    float f;
} OBJECT;

void print_obj(const OBJECT* obj)
{
    printf("%d, %f\n", obj->i, obj->f);

    // obj->i = 42;
    // obj->f = 10.5;
}

int main(void)
{
    OBJECT obj = { 10, 3.14 };
    print_obj(&obj);

    return 0;
}
#endif

// 해결 방법 2. 읽기 전용 포인터의 typedef도 함께 제공합니다.
//   => 전통적인 Windows API의 구현 방식
typedef struct obj {
    int i;
    float f;
} OBJECT, *POBJECT;

typedef const OBJECT* PCOBJECT;

void print_obj(PCOBJECT obj)
{
    printf("%d, %f\n", obj->i, obj->f);

    // obj->i = 42;
    // obj->f = 10.5;
}

int main(void)
{
    OBJECT obj = { 10, 3.14 };
    print_obj(&obj);

    return 0;
}
