// 4_표현식10.c
#include <stdio.h>

// 1) 포인터 + N
// => 허용되는 연산입니다.
// => 포인터 주소값 + N * sizeof(포인터 참조 타입)

// *(포인터 + N)
//  => 포인터[N] 동일합니다.

// * 배열은 이름은 배열의 첫번째 원소의 시작주소로 해석됩니다.
//  arr => &arr[0] => &*(arr + 0) => arr
//                   ---
//                   상쇄
#if 0
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
#endif

// C
void print_array(int* arr, int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
}

// C++ => 반개 구간
//  : [begin, end)
void print_array2(int* begin, int* end)
{
    int* p = begin;
    while (p != end) {
        printf("%d\n", *p);
        ++p;
    }
}

int main(void)
{
    //             p1                        arr + 9     arr + 10
    //              |                           |            |
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 마지막 다음 요소

    int* p1 = arr; /* OK */
    int* p2 = arr + 9; /* OK */

    // 배열의 끝을 넘은 다음 요소를 주소로 가르키는 것은 허용됩니다. => past the end
    int* p3 = arr + 10;

    // 주소를 참조하는 것은 허용되지만, 읽기/쓰기 참조의 동작은 미정의 동작입니다.
    *p3 = 100;
    printf("%d\n", *p3);

    // int* p4 = arr + 11; /* 미정의 동작 */

    print_array(arr, 10);
    print_array2(arr, arr + 10); // print_array2(std::begin(arr), std::end(arr));

    return 0;
}
