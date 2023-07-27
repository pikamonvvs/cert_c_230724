// 4_표현식11.c
#include <stdio.h>

// 포인터 + N
//  : 포인터 + N * sizeof(대상체 타입)

// 포인터 - N
//  : 포인터 - N * sizeof(대상체 타입)

int main(void)
{
    //                         p-1 p
    //                          |  |
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int* p = arr + 5;
    printf("%d\n", *(p - 1)); // *(p + (-1))
    printf("%d\n", p[-1]);

    return 0;
}
