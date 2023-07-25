// 3_선언4.c
#include <stdio.h>

// 2) 열거형 상수
#if 0
enum {
    SRC_SIZE = 10,
    DEST_SIZE = 10
};
// - 컴파일 시점에 평가되는 상수 입니다.
// - 상수 표현식으로 취급됩니다.
// - 오직 정수에 대해서만 사용할수 있습니다.

int main(void)
{
    int arr1[SRC_SIZE];
    int arr2[DEST_SIZE];

    int x = 0;
    switch (x) {
    case SRC_SIZE:
        break;
    }

    return 0;
}
#endif

// 3) 매크로 상수
// > 컴파일 시점에 상수로 치환되기 때문에
//   상수 표현식에서 사용할 수 있습니다.
// > 타입의 제한 없이 사용할 수 있습니다.
// => 전처리 이후에 심볼의 정보가 사라지기 때문에,
//    문제를 파악하기 어려울 수 있습니다.

#define SRC_SIZE 10
#define DEST_SIZE 10

int main(void)
{
    int arr1[SRC_SIZE];
    int arr2[DEST_SIZE];

    int x = 0;
    switch (x) {
    case SRC_SIZE:
        break;
    }

    return 0;
}
