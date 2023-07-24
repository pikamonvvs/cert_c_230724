// 2_전처리기10.c
#include <stdio.h>

// 매크로 함수
// 1) 호출하지 않고, 전처리 과정에서 텍스트 치환을 수행합니다.
//   => 함수 호출 오버헤드가 존재하지 않습니다.

// 2) 타입에 종속적이지 않은 함수를 구현할 수 있습니다.
#define ABS(x) ((x) > 0 ? (x) : -(x))

// 타입에 따라서, 여러개의 함수를 제공해야 합니다.
// 동일한 이름의 함수를 여러개 제공할 수 없습니다.
// => 각 타입에 따라서 다른 이름의 함수를 구현해야 합니다.
static inline int iabs(int x) { return x > 0 ? x : -x; }
static inline double dabs(double x) { return x > 0 ? x : -x; }
static inline long long llabs(long long x) { return x > 0 ? x : -x; }

int main(void)
{
    int n = -10;
    printf("%d\n", ABS(n));
    printf("%d\n", iabs(n));

    double d = -3.14;
    printf("%lf\n", ABS(d));
    printf("%lf\n", dabs(n));

    return 0;
}
