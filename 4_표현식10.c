// 4_표현식10.c
#include <stdio.h>

// 포인터 + N
// => 허용되는 연산입니다.
// => 포인터 주소값 + N * sizeof(포인터 참조 타입)

// *(포인터 + N)
//  => 포인터[N] 동일합니다.

// * 배열은 이름은 배열의 첫번째 원소의 시작주소로 해석됩니다.
//  arr => &arr[0] => &*(arr + 0) => arr
//                   ---
//                   상쇄

int main(void)
{
    //             p1  p1+1
    //              |  |
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
    int* p1 = arr; // &arr[0];

    printf("%d\n", *p1);
    printf("%d\n", *(p1 + 1)); // 2
    printf("%d\n", p1[1]);

    printf("%d\n", *arr);
    printf("%d\n", *(arr + 1)); // 2
    printf("%d\n", arr[1]);

    return 0;
}
