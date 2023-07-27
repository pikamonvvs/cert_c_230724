// 4_표현식13.c
#include <stdio.h>

// ++, --
// => 증감 연산자
//  : 다른 연산과 복합적으로 사용할 경우,
//    미정의 동작이 발생하지 않도록 주의해야 합니다.
#if 0
void func(int a, int b)
{
    printf("%d %d\n", a, b);
}

int main(void)
{
    int i = 2;
    // func(i++, i); /* 미정의 동작 */

    func(i, i);
    i++;

    return 0;
}
#endif

void func(int a, int b)
{
    printf("%d %d\n", a, b);
}

int global = 0;
int f1(void)
{
    return global + 10;
}

int f2(void)
{
    global = 100;
    return 20;
}

int main(void)
{
    // 함수의 인자를 전달할 때, 함수의 호출이 존재한다면
    // 앞에서부터 판단될지, 뒤에서부터 판단될지는 미지정 동작입니다.
    // func(f1(), f2());

    // 해결방법: 함수의 인자를 전달할 때, 함수의 호출을 분리하는 형태로
    //         작성해야 합니다.
    int r2 = f2();
    int r1 = f1();

    func(r1, r2);

    return 0;
}
