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

// 3. 매크로 치환 영역을 괄호로 감싸주어서,
//    우선순위 문제가 발생하는 것을 해결해야 합니다.
// #define SQUARE(x) x * x
#if 0
#define SQUARE(x) (x) * (x)

int main(void)
{
    // printf("pi: %lf\n", 3.14);
    printf("pi: %lf\n", PI);

    int x = 10;
    int result1 = square(x);
    printf("%d\n", result1);

    int result2 = SQUARE(x);
    printf("%d\n", result2);

    int result3 = square(x + x);
    printf("%d\n", result3);

    int result4 = SQUARE(x + x);
    // int result4 = x + x * x + x;
    // int result4 = (x + x) * (x + x);
    printf("%d\n", result4);

    return 0;
}
#endif

int dbl(int x)
{
    return x + x;
}

// #define DBL(x) (x) + (x)

// 4. 매크로 전체 치환영역을 괄호로 감싸주어야 합니다.
#define DBL(x) ((x) + (x))

int main(void)
{
    int x = 10;

    int result1 = DBL(x + x) * DBL(x + x);
    // int result1 = (x + x) + (x + x) * (x + x) + (x + x);

    printf("result1: %d\n", result1);

    int result2 = dbl(x + x) * dbl(x + x);
    printf("result2: %d\n", result2);

    return 0;
}
