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
#if 0
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
#endif

void inc1(int* a, int* b, int* x)
{
    *a += *x;
    *b += *x;
}
/*
inc1    PROC
        mov     eax, DWORD PTR [r8]          ; eax = *x
        add     DWORD PTR [rcx], eax         ; *a += eax
        mov     eax, DWORD PTR [r8]          ; eax = *x
        add     DWORD PTR [rdx], eax         ; *b += eax
        ret     0
inc1    ENDP
*/

// restrict는 불러온 메모리에 대해서, 변경 가능성이 없다(중첩된 영역이 아니다)고 판단해서,
// 메모리로부터 참조하는 연산을 최적화합니다.
void inc2(int* restrict a, int* restrict b, int* restrict x)
{
    *a += *x;
    *b += *x;
}
/*
inc2    PROC                                            ; COMDAT
        mov     eax, DWORD PTR [r8]          ; eax = *x;
        add     DWORD PTR [rcx], eax         ; *a += eax;
        add     DWORD PTR [rdx], eax         ; *b += eax;
        ret     0
inc2    ENDP
*/

int main(void)
{
    int a = 10;

    inc1(&a, &a, &a);
    printf("%d\n", a); // 40

    a = 10;
    inc2(&a, &a, &a);
    printf("%d\n", a); // 30

    return 0;
}

#if 0
int main(void)
{
    int a = 10;
    int b = 20;
    int x = 100;

    inc1(&a, &b, &x);
    printf("%d %d %d\n", a, b, x);

    a = 10;
    b = 20;
    x = 100;
    inc2(&a, &b, &x);
    printf("%d %d %d\n", a, b, x);

    return 0;
}
#endif
