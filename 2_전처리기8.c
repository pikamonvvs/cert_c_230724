// 2_전처리기8.c
#include <stdio.h>

// 예외 3. 상수 표현식(컴파일 시간에 판단될 수 있습니다.)이 필요할 때
#define DIV2(x) ((x) / 2)
static inline int div2(int x) { return x / 2; }

// 상수 표현식이 필요한 경우
// 1) enum의 초기값
enum {
    // N1 = div2(10)
    N1 = DIV2(10)
};

// 2) 전역 / 정적 지역 변수의 초기값(상수 표현식이 필요합니다)
// int x = div2(10);
int x = DIV2(10);
void foo(void)
{
    // static int sx = div2(10);
    static int sx = DIV2(10);
}

// 3) 배열의 크기
// int arr[div2(10)];
int arr[DIV2(10)];

int main(void)
{

    // int n = 10 / 2;

    return 0;
}
