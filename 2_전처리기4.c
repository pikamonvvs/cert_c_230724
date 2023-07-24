// 2_전처리기4.c
#include <stdio.h>

int cnt = 0;

void print_cnt(void)
{
    printf("cnt = %d\n", cnt);
}

#define CALL_FUNC(fp) (++cnt, fp())

int main(void)
{
    CALL_FUNC(print_cnt);
    CALL_FUNC(print_cnt);
    CALL_FUNC(print_cnt);

    return 0;
}
