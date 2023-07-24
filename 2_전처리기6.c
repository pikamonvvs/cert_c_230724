// 2_전처리기6.c

// * 매크로 함수가 인라인 함수로 대체할 수 있다면,
//   인라인 함수가 선호되어야 합니다.
// => 매크로 함수를 함수 호출의 오버헤드를 제거하기 위해서 사용하는 경우

// 예외 1. 매크로 함수를 사용해서, 토큰을 연결하거나, 문자열 변경 기능을 이용하는 경우
//  ##: 두개의 토큰을 하나의 토큰으로 만들어줍니다.
//   A##B => AB

//   #: 토큰을 문자열로 변경해줍니다.
//    #A  => "A"

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

// 토큰을 문자열로 변경하거나, 토큰을 연결하는 작업은
// 반드시 이중으로 처리해야 합니다.
// => 매크로의 치환 이후에 작업이 수행되어야 하기 때문입니다.

#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define TO_STR_IMPL(str) #str
#define TO_STR(str) TO_STR_IMPL(str)

#define HELLO hello

int main(void)
{
    int hello10 = 100;
    printf("%d\n", CONCAT(hello, 10));
    //             hello##10 => hello10

    printf("%d\n", CONCAT(HELLO, 10));
    //             => CONCAT_IMPL(hello, 10)
    //             => hello##10
    //             => hello10

    printf("%s\n", TO_STR(hello));
    // #hello => "hello"

    printf("%s\n", TO_STR(HELLO));
    //  TO_STR(HELLO)
    //  => TO_STR_IMPL(hello)
    //  => #hello
    //  => "hello"

    return 0;
}
