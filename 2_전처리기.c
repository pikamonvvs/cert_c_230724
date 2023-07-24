// 2_전처리기.c

#include <stdio.h>

// 1. 빌드 과정
//  - 전처리(preprocessor) => 컴파일(Compile)    => 링크(Link)
//   #define / #include      단위: 파일           a.o + b.o   => a.exe/a.out
//   #ifdef / #if          a.c => a.o / a.obj
//    "텍스트 처리"           b.c => b.o / b.obj

// 매크로 상수
#define PI 3.14

int square(int x) { return x * x; }

// 2. 함수 호출의 오버헤드를 제거하기 위해서,
//    매크로 함수를 사용할 수 있습니다.
//  > 매크로 함수는 대문자로 이름을 사용하는 것이 일반적입니다.
#define SQUARE(x) x* x

int main(void)
{
    // printf("pi: %lf\n", 3.14);
    printf("pi: %lf\n", PI);

    int x = 10;
    int result1 = square(x);
    printf("%d\n", result1);

    int result2 = SQUARE(x);
    printf("%d\n", result2);

    return 0;
}
