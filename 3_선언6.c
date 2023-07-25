// 3_선언6.c
#include <stdio.h>

#if 0
enum {
    ARRAY_SIZE = 10
};

// 문제점
// : 수명이 끝난 변수의 주소를 참조하는 문제가 있습니다.
//  "미정의 동작"

void init_array(int** ptr_param)
{
    int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }

    *ptr_param = arr;
}

int main(void)
{
    int* ptr;
    init_array(&ptr);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", ptr[i]);
    }

    return 0;
}
#endif

#if 0
enum {
    ARRAY_SIZE = 10
};

// 해결방법 1. 정적 메모리
// => 함수가 재진입이 불가능합니다.
//   "스레드 안전성"이 없습니다.
// => strtok
//   "재진입이 불가능한 대표적인 표준 라이브러리 함수"

void init_array(int** ptr_param)
{
    static int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }

    *ptr_param = arr;
}

int main(void)
{
    int* ptr;
    init_array(&ptr);

    int* ptr2;
    init_array(&ptr2);

    ptr2[3] = 10000;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", ptr[i]);
    }

    return 0;
}
#endif

#include <stdlib.h> // malloc, free
#include <string.h>

// 해결방법 2. 동적 메모리 할당
// 1) malloc은 실패 가능성이 존재합니다.
// 2) free하지 않으면, 메모리가 누수됩니다.
//    별도의 함수를 통해 할당된 메모리는 누수의 위험성이 높습니다.
// 3) malloc은 메모리 할당의 성능적인 오버헤드가 있습니다.
// => 동적 메모리 할당을 사용하지 않는 권장합니다. MISRA
// => strdup
//     : 인자로 받은 문자열을 동적 메모리할당하여 복사합니다.
#if 0
void init_array(int** ptr_param)
{
    int* arr = malloc(sizeof(int) * ARRAY_SIZE);
    if (arr != NULL) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            arr[i] = i + 1;
        }
    }

    *ptr_param = arr;
}

int main(void)
{
    int* ptr;
    init_array(&ptr);

    int* ptr2;
    init_array(&ptr2);

    ptr2[3] = 10000;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", ptr[i]);
    }

    char* s = strdup("hello");
    printf("%s\n", s);

    free(s); // !!!

    return 0;
}
#endif

// 핵심: C에서 함수를 설계할 때,
//      메모리를 할당해서, 주소를 결과로 주는 형태의 함수는 지양해야 합니다.
//      함수를 사용하는 사용자쪽에서 메모리를 제공하는 형태로 설계되어야 합니다.
#if 0
enum {
    ARRAY_SIZE = 10
};

// 배열을 인자로 전달하면, 배열의 첫번째 원소의 시작 주소가 전달됩니다.
//  - void init_array(int arr[ARRAY_SIZE])

// 배열을 인자로 전달할 때, 포인터로 표기하는 것이 좋습니다.
void init_array(int* arr)
{
    printf("%zu\n", sizeof(arr)); // 8

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }
}

int main(void)
{
    int arr[ARRAY_SIZE];
    init_array(arr);
    // 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
#endif

// C/C++ 에서 변수의 타입을 구하는 방법
// : 식별자를 제외한 나머지가 타입입니다.
// int  n;  => int
// int *p;  => int *

// Decay(부식)
// => 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
// 예외
// 1) sizeof
// 2) &
#if 0
int main(void)
{
    int x[3] = { 10, 20, 30 };
    // x의 타입은 무엇인가요?
    //   int[3]

    // int* p = x;
    int* p = &x[0];
    // 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
    // => Decay

    printf("%zu\n", sizeof(p)); // 8
    printf("%zu\n", sizeof(int*));

    printf("%zu\n", sizeof(x)); // 12
    printf("%zu\n", sizeof(int[3]));

    // p2는 어떤 타입되어야 할까요?
    //  - x는 int[3] 타입으로 정확하게 해석됩니다.

    int(*p2)[3]; // p2 ----->  int[3]
    p2 = &x;

    (*p2)[0] = 100;
    (*p2)[1] = 200;
    (*p2)[2] = 300;

    return 0;
}
#endif

void print_array(int (*x)[2], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%3d ", x[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int x[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
    // 1) x는 어떤 타입인가요?
    // : x[3][2]

    // 2) x의 배열의 길이는 얼마인가요?
    // : 3개 크기의 배열입니다. 하나의 원소 타입이 int[2] 입니다.
    //  [ int[2] ][ int[2] ][ int[2] ]
    print_array(x, 3);

    printf("%lu\n", sizeof(x) / sizeof(x[0])); // 3

    int arr[5];

    // 배열의 길이를 구하는 연산
    // printf("%lu\n", sizeof(arr) / sizeof(int));
    printf("%lu\n", sizeof(arr) / sizeof(arr[0]));

    return 0;
}
