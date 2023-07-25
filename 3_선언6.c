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

enum {
    ARRAY_SIZE = 10
};

void init_array(int arr[ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }
}

int main(void)
{
    int arr[ARRAY_SIZE];
    init_array(arr);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
