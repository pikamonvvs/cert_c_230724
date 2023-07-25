// 3_선언5.c
#include <stdio.h>
#include <assert.h>

// 1) 구조체의 크기는 플랫폼에 따라 달라질 수 있습니다.
// 2) 구조체를 통해 파일에 저장하거나, 데이터의 교환을 목적으로 사용할 경우,
//    패딩을 제거하는 형태로 사용해야 합니다.

// #pragma pack(1) // 컴파일러 확장 명령

// assert
// 1) assert(단언문)은 취약성이 있는 소프트웨어의 결함을 찾아서 제거하는데 사용되는
//    효과적인 진단 도구 입니다.
// 2) 조건이 성립되지 않을 경우, abort() 를 통해 프로세스를 비정상 종료합니다.
// 3) NDEBUG가 정의되어 있으면, assert는 아무 동작도 수행하지 않습니다.

// 제약사항
// 1) 프로그램 실행 중에 동작하기 때문에, 실행 시간 오버헤드가 존재합니다.
// 2) assert의 비정상 종료는 abort()를 호출하기 때문에,
//    서버 프로그램이나 임베디드 시스템에서 사용하기 어렵습니다.

// => 조건식을 컴파일 시간에 체크할 수 있다면,
//    static_assert를 이용하는 것이 좋습니다.
//     C11: static_assert / _Static_assert
//   C++11: static_assert
//   - 조건이 성립되지 않는다면, 컴파일 오류가 발생합니다.
//   => static_assert를 사용하는 것이 좋습니다.

#if 0
#include <stdlib.h>

#ifndef NDEBUG
#define xassert(expr)                                         \
    do {                                                      \
        if (!(expr)) {                                        \
            fprintf(stderr, "Assertion failed: %s\n", #expr); \
            abort();                                          \
        }                                                     \
    } while (0)
#else
#define xassert(expr) (void)0
#endif

struct packet {
    unsigned char cmd;
    int len;
    // ...
};

void process(struct packet* packet)
{
    // 반드시 구조체의 크기가 5이어여 합니다.
    // assert(sizeof(struct packet) == 5);
    // static_assert(sizeof(struct packet) == 5, "Size must be 5");
    _Static_assert(sizeof(struct packet) == 5, "Size must be 5");

    printf("process\n");
}

int main(void)
{
    printf("size: %zu\n", sizeof(struct packet));

    struct packet packet = { 0 };
    process(&packet);

    return 0;
}
#endif

// static_assert를 직접 구현해서 사용할 수 있습니다.
// 배열의 크기를 음수로 지정할 수 없는 특징을 이용합니다.
//  : int arr[-1]; /* 에러 */

#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define STATIC_ASSERT(expr, message) \
    typedef char CONCAT(assertion_failed_at_line_, __LINE__)[(expr) ? 1 : -1]

int main(void)
{
    STATIC_ASSERT(sizeof(long) == 8, "long size must be 8");
    // STATIC_ASSERT(sizeof(long) == 4, "long size must be 4");

    return 0;
}
