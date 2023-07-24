// 2_전처리기4.c
#include <stdio.h>

#if 0
int cnt = 0;

void print_cnt(void)
{
    printf("cnt = %d\n", cnt);
}

#define CALL_FUNC(fp) (++cnt, fp())
// 위의 함수를 일반 함수(인라인 함수)로 변경해야 합니다.

int main(void)
{
    // cnt라는 지역 변수가 존재하면, 아래 코드는 결과가 제대로 나오지 않습니다.
    int cnt = 10;

    CALL_FUNC(print_cnt); // (++cnt, print_cnt());
    CALL_FUNC(print_cnt); // (++cnt, print_cnt());
    CALL_FUNC(print_cnt); // (++cnt, print_cnt());

    return 0;
}
#endif

#if 0
int cnt = 0;

void print_cnt(void)
{
    printf("cnt = %d\n", cnt);
}

// #define CALL_FUNC(fp) (++cnt, fp())
// 위의 함수를 일반 함수(인라인 함수)로 변경해야 합니다.
static inline void call_func(void (*fp)(void))
{
    ++cnt;
    fp();
}

int main(void)
{
    int cnt = 10;

    call_func(print_cnt); // (++cnt, print_cnt());
    call_func(print_cnt); // (++cnt, print_cnt());
    call_func(print_cnt); // (++cnt, print_cnt());

    return 0;
}
#endif
