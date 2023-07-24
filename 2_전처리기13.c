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
#if 0
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
#endif

// 문제점
// - 매크로 함수의 인자로 전달되는 식별자와 매크로 함수 내부에서 생성하는 변수의 식별자가 충돌할 때
//   의도하지 않은 결과가 발생할 수 있습니다.
// - 매크로 함수에서 생성되는 식별자가 충돌 가능성이 낮은 이름을 사용해야 합니다.

#if 0
#define SWAP(a, b)     \
    do {               \
        int __tmp = a; \
        a = b;         \
        b = __tmp;     \
    } while (0)
#endif

#if 0
#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define UNIQUE_NAME(a, b) CONCAT(a, b)

#define SWAP(a, b)                            \
    do {                                      \
        int UNIQUE_NAME(__tmp, __LINE__) = a; \
        a = b;                                \
        b = UNIQUE_NAME(__tmp, __LINE__);     \
    } while (0)

int main(void)
{
    int a = 10;
    int tmp = 20;

    SWAP(a, tmp);
    // do { int __tmp67 = a; a = tmp; tmp = __tmp67; } while (0);

    printf("%d %d\n", a, tmp);

    return 0;
}
#endif

// 해결 방법 1.
//  => 타입 인자를 추가적으로 전달 받습니다.
#if 0
#define SWAP(a, b)     \
    do {               \
        int __tmp = a; \
        a = b;         \
        b = __tmp;     \
    } while (0)
#endif

#if 0
#define SWAP(type, a, b) \
    do {                 \
        type __tmp = a;  \
        a = b;           \
        b = __tmp;       \
    } while (0)
#endif

// 해결 방법 2. GNU Extension
//  => __typeof
//    C++11: decltype 문법과 동일합니다.

//  => 매크로 함수를 만들 때, do-while(0) 이외의 방법도 제공합니다.
//     ({...})
//      - MSVC는 지원하지 않습니다.

#define SWAP(a, b)             \
    ({                         \
        __typeof(a) __tmp = a; \
        a = b;                 \
        b = __tmp;             \
    })

int main(void)
{
    int a = 10;
    int b = 20;

    SWAP(a, b);

    printf("%d %d\n", a, b);

    return 0;
}
