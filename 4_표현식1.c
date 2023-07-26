// 4_표현식1.c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main(void)
{
    int (*fp)(int a, int b) = NULL;

    fp = &add;
    printf("%d\n", (*fp)(10, 20));

    fp = sub; // 함수의 이름은 함수의 주소(함수 포인터)로 해석됩니다. - Decay
    printf("%d\n", fp(10, 20)); // 함수 포인터를 참조 없이 호출하는 것을 허용합니다.

    return 0;
}
