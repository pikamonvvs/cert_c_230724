// 4_표현식8.c
#include <stdio.h>

// 비트 필드 구조체
// : 구조체의 저장 효율을 향상시킬 수 있습니다.

// 일반적인 멤버는 순차적으로 배치되는 것이 보장됩니다.
struct s2 {
    int a;
    int b;
    int c;
};

#if 1
struct s {
    unsigned int m1 : 8;
    unsigned int m2 : 8;
    unsigned int m3 : 8;
    unsigned int m4 : 8;
};

// 위의 구조체가 어떤 순서로 배치될지는,
// 미지정 사항입니다.
// => 비트 필드 멤버가 어떤 순서로 배치될지 가정하는 코드를 작성하면 안됩니다.

// low                    high
//  [ m1 ][ m2 ][ m3 ][ m4 ]

// low                    high
//  [ m4 ][ m3 ][ m2 ][ m1 ]

int main(void)
{
    printf("%zu\n", sizeof(struct s));

    struct s data = { 0 };

    // unsigned char* ptr = (unsigned char*)&data;
    // ++(*ptr); // m1을 증가하는 연산
    (data.m1)++;

    printf("%d\n", data.m1);

    return 0;
}
#endif

#if 0
// Little Endian
// low
//  [ 0x78 ][ 0x56 ][ 0x34 ][ 0x12 ]

// Big Endian
// low
//  [ 0x12 ][ 0x34 ][ 0x56 ][ 0x78 ]

int main(void)
{
    int n = 0x12345678;
    // unsigned char n[4] = { 0x12, 0x34, 0x56, 0x78 };
    unsigned char* p = (unsigned char*)&n;

    printf("%x %x %x %x\n", p[0], p[1], p[2], p[3]);

    return 0;
}
#endif
