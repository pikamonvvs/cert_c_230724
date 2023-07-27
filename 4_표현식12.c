// 4_표현식12.c
#include <stdio.h>

enum {
    BUF_SIZE = 5
};

// 아래 코드의 문제점은 무엇일까요?
int main(void)
{
    char buf[BUF_SIZE];
    char* cur;

    cur = buf;
    while (cur < buf + sizeof(buf)) {
        *cur = 0;
        printf("%d\n", *cur);
        cur++;
    }

    return 0;
}
