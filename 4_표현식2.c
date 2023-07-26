// 4_표현식2.c
#include <stdio.h>

// 실제 KQUEUE 라이브러리의 구현에 있는 코드 입니다.
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main(void)
{
    struct timeval tv;
    unsigned long junk;

    gettimeofday(&tv, NULL);

    srand(tv.tv_sec ^ tv.tv_usec ^ junk);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());

    return 0;
}
