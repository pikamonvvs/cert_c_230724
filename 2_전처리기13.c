// 2_전처리기13.c
#include <stdio.h>

#define SWAP(a, b) \
    int tmp = a;   \
    a = b;         \
    b = tmp;

int main(void)
{
    int a = 10;
    int b = 20;

    SWAP(a, b);
    printf("%d %d\n", a, b);

    return 0;
}
