// 4_표현식1.c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

// 다른 타입의 함수 포인터를 통해, 함수를 호출하는 것은
// 미정의 동작입니다.

int main(void)
{
    int (*fp)(int a, int b) = NULL;

    // C++
    fp = &add;
    printf("%d\n", (*fp)(10, 20));

    // C
    fp = sub; // 함수의 이름은 함수의 주소(함수 포인터)로 해석됩니다. - Decay
    printf("%d\n", fp(10, 20)); // 함수 포인터를 참조 없이 호출하는 것을 허용합니다.

    int (*fp2)(int a, int b, int c);
    fp2 = &add;

    printf("fp2: %d\n", fp2(10, 20, 30)); /* 미정의 동작 */

    return 0;
}
