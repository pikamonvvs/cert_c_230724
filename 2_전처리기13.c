// 2_전처리기13.c
#include <stdio.h>

#if 0
#define SWAP(a, b) \
    int tmp = a;   \
    a = b;         \
    b = tmp;
#endif
/* 동일한 이름의 변수를 만들었을 때, 컴파일 오류가 발생합니다. */

#if 0
#define SWAP(a, b)   \
    {                \
        int tmp = a; \
        a = b;       \
        b = tmp;     \
    }
#endif
/* 세미 콜론을 사용하지 않을 경우, 컴파일 오류가 발생하지 않습니다.*/

// 핵심: 복수 구문 매크로 함수는 do{} while(0)로 감싸야 합니다.
#define SWAP(a, b)   \
    do {             \
        int tmp = a; \
        a = b;       \
        b = tmp;     \
    } while (0)

int main(void)
{
    int a = 10;
    int b = 20;

    // int tmp; /* 동일한 이름의 변수를 만들었을 때, 컴파일 오류가 발생합니다. */

    SWAP(a, b);
    printf("%d %d\n", a, b);

    return 0;
}
