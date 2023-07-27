#include <stdio.h>
#include <stddef.h>

// 아래 코드는 OpenBSD 리눅스의 make에서 발견된 문제점 입니다.
// 어떤 문제가 있을까요?
struct big {
    unsigned long long ull_1;
    unsigned long long ull_2;
    unsigned long long ull_3;
    int si_4;
    int si_5;
};

// https://cnst.livejournal.com/24040.html
int f(void)
{
    size_t skip = offsetof(struct big, ull_2);
    struct big* s = (struct big*)malloc(sizeof(struct big));
    if (!s) {
        return -1;
    }

    // 포인터의 산술 연산을 수행할 때, 바이트 단위의 처리를 위해서는
    // 명시적으로 char* 타입으로의 캐스팅이 필요합니다.
    // memset(s + skip, 0, sizeof(struct big) - skip); /* 잘못된 연산 */

    // 해결 방법
    memset((char*)s + skip, 0, sizeof(struct big) - skip);

    /* ... */
    free(s);
    s = NULL;

    return 0;
}

int main(void)
{
}
