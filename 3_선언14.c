// 3_선언14.c
#include <stdio.h>
#include <string.h>

// void* memcpy( void *restrict dest, const void *restrict src, size_t count );

// * restrict 제한자
// : C99에 새롭게 도입되었습니다.
//   포인터가 가리키는 영역에서 "같은 메모리 공간을 참조하지 않는다."라는 한정자입니다.
//   "컴파일러가 최적화에 활용합니다."
//  => restrict로 지정되어 있는 인자로
//     같은 메모리 공간에 대한 참조가 발생할 수 있는 주소를 전달하면
//     "미정의 동작"이 발생합니다.
void print_data(int* data, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%2d ", data[i]);
    }
    printf("\n");
}

// src  dest
//      |-----------------------|
// |xxxxxxxxxxxxxxxxxxxxxxx|
// [ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ]

int main(void)
{
    int data[10] = { 1, 2, 3, 4, 5 };
    print_data(data, 10);

    // memcpy(data + 1, data, sizeof(int) * 5);
    memmove(data + 1, data, sizeof(int) * 5);
    print_data(data, 10);

    return 0;
}
