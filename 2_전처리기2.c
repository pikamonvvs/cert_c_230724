// 2_전처리기2.c
#include <stdio.h>

// * 정리
// 1) 매크로 함수를 사용할 때, 매개 변수에 대해서 괄호를 사용해야 합니다.
// #define SQUARE(x) (x) * (x)

// 2) 매크로 함수/상수를 사용할 때, 치환 영역을 괄호로 감싸주어야 합니다.
// #define SQUARE(x) ((x) * (x))
// #define INFO (-1)

// * 예외
// 1) 단일 식별자 또는 함수 호출로 확장되는 매크로는
//    주변 식에 의해 연산자 우선순위의 영향을 받지 않기 때문에
//    괄호를 묶어줄 필요가 없습니다.
int GetPid(void) { return 42; }

#define GET_PID GetPid
#define MY_PID GetPid()

int main(void)
{
    printf("%d\n", GetPid());
    printf("%d\n", GET_PID());
    printf("%d\n", MY_PID);

    return 0;
}
