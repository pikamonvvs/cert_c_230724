// 2_전처리기11.c
#include <stdio.h>

#define cstring char*
// 문제점: 매크로 정의는 타입에 대한 범위 규칙이 제대로 적용되지 않습니다.
// 해결방법
//  => 타입에 대해서 재정의할 때는 typedef를 이용해야 합니다.

int main(void)
{
    cstring s = "hello";
    printf("%s\n", s);

    cstring s1, s2;
    // char* s1, s2;
    // s1 -> char*
    // s2 -> char
    printf("%zd\n", sizeof(s1));
    printf("%zd\n", sizeof(s2));

    return 0;
}
