// 4_표현식11.c
#include <stdio.h>

#if 0
// * 포인터 + N
//  : 포인터 + N * sizeof(대상체 타입)

// * 포인터 - N
//  : 포인터 - N * sizeof(대상체 타입)
int main(void)
{
    //                         p-1 p
    //                          |  |
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // * 배열의 이름을 기반으로는 허용하지 않습니다. -> arr[-1] => 미정의 동작

    int* p = arr + 5;
    printf("%d\n", *(p - 1)); // *(p + (-1))
    printf("%d\n", p[-1]);

    return 0;
}
#endif

// * 포인터 + 포인터 => 허용되지 않는 연산입니다.
// * 포인터 - 포인터 => 허용되는 연산입니다.
//                   동일한 배열을 참조하는 포인터에 대해서만 사용해야 합니다.
//                 포인터간의 상대적 위치를 파악하는 목적으로 사용할 수 있습니다.
//   포인터1 - 포인터2
//   => (포인터1 - 포인터2) / sizeof(대상체 타입)
#if 0
int main(void)
{
    int arr[5] = { 1, 2, 3, 4, 5 };

    int* p1 = arr;
    int* p2 = arr + 2;
    // ptrdiff_t => long
    printf("%ld\n", p1 - p2); // 같은 배열을 참조하는 포인터이므로 허용됩니다.
    printf("%ld\n", p2 - p1); // 같은 배열을 참조하는 포인터이므로 허용됩니다.

    int x[3] = { 10, 20, 30 };
    p2 = x;

    // 다른 배열을 참조하는 포인터간의 뺄셈은 허용되지 않습니다.
    printf("%ld\n", p1 - p2); // 미정의 동작
    printf("%ld\n", p2 - p1); // 미정의 동작

    return 0;
}
#endif

/*
struct point {
    int x;
    int y;
};

// * 포인터 간의 관계 연산자 >, <, >=, <= 는
//   동일한 대상체를 가리키는 경우에만 사용해야 합니다.
int main(void)
{
    int a1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int* p1 = a1 + 3;
    int* p2 = a1 + 5;
    if (p1 < p2) {
        // ...
    }

    struct point pt = { 10, 20 };

    int* p3 = &pt.x;
    int* p4 = &pt.y;
    if (p3 > p4) {
        // ...
    }

    return 0;
}
*/

// 핵심: 포인터의 타입은 포인터의 산술 연산에서의 오프셋(단위)을 결정합니다.
//  GCC: -pedantic
//    표준적인 연산이 아닌 경우, 경고를 확인할 수 있습니다.
#if 0
int main(void)
{
    // void* => 가르키는 대상체 타입의 정보가 존재하지 않습니다.
    //  목적: 모든 타입의 주소를 담을 수 있습니다.
    int n = 42;
    double d = 3.14;

    void* p1 = &n;
    void* p2 = &d;
    // 참조를 비롯한 연산을 수행할 수 없습니다.

    void* p = NULL;
    // printf("%ld\n", (long)(p + 1)); // 표준이 아닙니다. GCC 확장

    printf("%ld\n", (long)((char*)p + 1));

    return 0;
}
#endif

// * 핵심
// 포인터 연산
// - C 컴파일러는 포인터 연산시 배열(대상체)의 경계를 초과했는지 컴파일 타임에 검사하지 않습니다.
// - C 컴파일러는 포인터 연산이 유효한 메모리를 참조하는지 컴파일 타임에 검사하지 않습니다.
// - C 컴파일러는 배열의 첨자 연산이 실행 시간에 경계를 초과하는지 검사하지 않습니다.
// => 잘못 사용할 경우, 미정의 동작의 위험성이 있습니다.
