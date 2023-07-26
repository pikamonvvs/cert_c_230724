// 4_표현식5.c
#include <stdio.h>

// 1) 구조체가 멤버가 아무것도 존재하지 않을 경우,
//    사이즈는 0 입니다.

// 비어있는 구조체는 미정의 사항입니다.
#if 0
struct AAA {
};
#endif

// 2) C 표준에서 구조체는 멤버를 1개 이상 제공해야 합니다.
// 3) 구조체의 크기는 멤버 변수의 총합과 일치하지 않을 수 있습니다.

// * C 표준
// - 구조체 내부에 이름없는 패딩이 포함될 수 있으며, 앞쪽에는 패딩이 존재하지 않습니다.
// - CPU가 구조체의 멤버에 접근하는 것을 효율적으로 수행하기 위해서 패딩이 필요합니다.
// - 구조체의 패딩이 어떤 형태로 생성되는지, 미지정 동작입니다.
//   => 컴파일러, 실행 환경에 따라 패딩이 달라질 수 있습니다.

struct AAA {
    int n;
    // char __padding1[4];
    double d;
    char c;
    // char __padding2[7];
};

struct BBB {
    int n;
    char c;
    double d;
};
// => 멤버 변수의 배치 순서에 따라, 패딩을 조절할 수 있습니다.
//    제한된 메모리 환경에서는 유용합니다.

int main(void)
{
    printf("%zu\n", sizeof(struct AAA));
    printf("%zu\n", sizeof(struct BBB));
    return 0;
}
