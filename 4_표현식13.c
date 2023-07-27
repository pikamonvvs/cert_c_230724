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

#if 0
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
#endif

struct AAA {
    void (*f)(struct AAA* p);
};

void foo(struct AAA* p)
{
    printf("foo\n");
}

void goo(struct AAA* p)
{
    printf("goo\n");
}

struct AAA* g(struct AAA* p)
{
    p->f = goo;
    return p;
}

int main(void)
{
    struct AAA aaa = { .f = foo };
    // aaa.f(NULL);

    // g(&aaa)의 결과로 f가 goo로 호출이 될 것인지,
    // 바뀌기 이전의 f인 foo가 호출될 것인지
    // => 미지정 동작입니다.

    // * 함수 포인터로 함수를 호출할 때, 인자를 통해 함수 포인터의 값을
    //   변경하는 행위는 안됩니다.
    // aaa.f = foo;
    // aaa.f(g(&aaa));

    // * 해결 방법: 함수의 호출 인자 안에서 부수 효과를 가지는 형태로
    //            코드를 작성하면 안됩니다.
    aaa.f = foo;
    struct AAA* r = g(&aaa);
    aaa.f(r);

    return 0;
}
