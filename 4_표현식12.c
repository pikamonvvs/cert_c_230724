// 4_표현식12.c
#include <stdio.h>

enum {
    BUF_SIZE = 5
};

// * 변수의 타입이 변경되어도, 알고리즘의 코드는 문제 없이 동작하도록 만들어주는 것이 좋습니다.

// 아래 코드의 문제점은 무엇일까요?
int main(void)
{
    char buf[BUF_SIZE];
    char* cur;

    //-----
#if 0
    cur = buf;
    while (cur < buf + sizeof(buf)) {
        *cur = 0;
        printf("%d\n", *cur);
        cur++;
    }
#endif

    // 해결 방법 1. 1 바이트 단위의 처리 코드는 char* 명시적인 캐스팅을
    //            항상 작성해야 합니다.
#if 0
    cur = buf;
    while ((char*)cur < (char*)buf + sizeof(buf)) {
        *cur = 0;
        printf("%d\n", *cur);
        cur++;
    }
#endif

#if 0
    // 해결 방법 2. 메모리의 크기를 기반으로 처리하기 보다는
    //            요소의 개수를 기반으로 처리하는 것이 좋습니다.
    cur = buf;
    while (cur < buf + BUF_SIZE) {
        *cur = 0;
        printf("%d\n", *cur);
        cur++;
    }
#endif

    for (int i = 0; i < BUF_SIZE; i++) {
        // printf("%d\n", *(cur + i));
        // 배열의 포인터 연산은 가독성이 떨어집니다.
        // 배열의 접근 연산을 사용하는 것이 더 좋습니다.
        printf("%d\n", cur[i]);
    }

    return 0;
}
