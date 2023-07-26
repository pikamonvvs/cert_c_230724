// 4_표현식2.c
#include <stdio.h>

// 실제 KQUEUE 라이브러리의 구현에 있는 코드 입니다.
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// 변수를 생성하였을 때의 쓰레기값을 랜덤 시드로 활용해서,
// 임의성을 높이는 방법으로 사용하였습니다.
// : https://kqueue.org/blog/2012/06/25/more-randomness-or-less/

// 문제점
// 1) 초기화되지 않은 변수를 참조하는 행위는 미정의 동작입니다.
// 2) 컴파일러는 초기화되지 않은 변수의 접근을 최적화하고, 결정적으로 이를 통해 예측 가능할 수
//    있습니다.
// => 암호화 같은 예측 불가능성의 의존하는 보안 알고리즘에서 불확실성에 대한 손실은
//    보안의 취약점으로 작용할 수 있습니다.

#if 0
int main(void)
{
    struct timeval tv;
    unsigned long junk;
    printf("%lu\n", junk);

    gettimeofday(&tv, NULL);

    srand(tv.tv_sec ^ tv.tv_usec ^ junk);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());

    return 0;
}
#endif

// 핵심
// => 어떤 의도를 가지든 간에,
//    초기화되지 않은 변수(지역 변수, 동적 메모리 할당)를
//    사용하는 것은 미정의 동작의 가능성이 있습니다.

int main(void)
{
    struct timeval tv;

    double cpu_time_used;
    cpu_time_used = ((double)clock()) / CLOCKS_PER_SEC;
    printf("%lf\n", cpu_time_used);

    gettimeofday(&tv, NULL);

    srand(tv.tv_sec ^ tv.tv_usec ^ (unsigned long)cpu_time_used);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());

    return 0;
}
