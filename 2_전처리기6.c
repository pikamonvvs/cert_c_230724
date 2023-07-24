// 2_전처리기6.c

// * 매크로 함수가 인라인 함수로 대체할 수 있다면,
//   인라인 함수가 선호되어야 합니다.
// => 매크로 함수를 함수 호출의 오버헤드를 제거하기 위해서 사용하는 경우

// 예외 1. 매크로 함수를 사용해서, 토큰을 연결하거나, 문자열 변경 기능을 이용하는 경우
#include <stdio.h>

enum Color {
    Color_Red,
    Color_Blue,
    Color_Green,
};

struct color {
    enum Color color;
    const char* name;
};

#if 0
struct color colors[] = {
    { Color_Red, "Red" },
    { Color_Blue, "Blue" },
    { Color_Green, "Green" },
};
#endif

#define COLOR(color)          \
    {                         \
        Color_##color, #color \
    }

struct color colors[] = {
    COLOR(Red), COLOR(Blue), COLOR(Green)
};

int main(void)
{
    return 0;
}
