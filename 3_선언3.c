// 3_선언3.c
#include <stdio.h>

// 1. 프로그램에서 상수 리터럴을 직접 사용할 경우,
//    소스 코드의 가독성이 떨어집니다.
// 2. 프로그램 코드에서 상수 리터럴을 직접 사용하는 대신, 적절하게 이름있는 심볼릭 상수를
//    사용해야 합니다.

// 3. C에서 심볼릭 상수를 만드는 3가지 방법
//  1) const 상수
//   => 런타임 상수입니다.
//      배열의 크기를 지정하는 등의 상수 표현식에서 사용할수 없습니다.
//     "변수에 상수성을 부여하는 용도로 밖에 사용할수 없습니다."
//   => C++에서는 컴파일 상수라는 개념이 도입되었습니다.
//      "상수 표현식에서 사용할 수 있습니다."

#if 0
const int SRC_SIZE = 10;
const int DEST_SIZE = 10;

enum {
    AAA = SRC_SIZE /* 오류 */
};

void foo(void)
{
    static int n = SRC_SIZE; /* 오류 */
}

int main(void)
{
    int arr1[SRC_SIZE] = { 10, 20, 30 }; /* 오류 */
    int arr2[DEST_SIZE] = { 100, 200, 300 }; /* 오류 */

    int x = 0;
    switch (x) {
    case SRC_SIZE: /* 오류 */
        break;
    }

    return 0;
}
#endif

// 컴파일 타임 상수 / 런타임 상수
// - 컴파일 타임 상수
//   => 값을 메모리로부터 읽지 않고, 컴파일 타임에 값을 결정합니다.

// - 런타임 상수
//   => 런타임 상수의 값을 읽기 위해서 메모리로부터 값을 로드합니다.
int main(void)
{
    const int c1 = 42;
    // C++: 컴파일 타임 상수
    //   C: 런타임 상수

    printf("%d\n", c1);
    // printf("%d\n", 42);

    int n = 42;
    const int c2 = n;
    // 런타임 상수 입니다.
}
