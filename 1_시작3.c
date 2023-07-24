// 1_시작3.c
#include <stdio.h>

// 1. 삼중자(trigraph)
//  => 특정 지역의 문자셋에 C의 문법에서 사용되는 핵심적인 문자가
//     제공되지 않아서, 제공하는 기능입니다.
//   ex) ??= => #
//       ??/ => \ ...
//  => 삼중자는 사용하지 않는 것이 원칙입니다.
//  => ??를 연속으로 사용하면 안됩니다.
//  => 최신 컴파일러는 삼중자를 기본적으로 비활성화하였습니다.
//     -trigraphs
//  => 표준 위원회에서 삼중자를 제거하자는 의견이 있었습니다.
//     C: 제외되지 않았습니다.
//   C++: 제외되었습니다. - C++17

// 2. 라인 주석을 사용하지 말아야 합니다.
//    라인 주석의 마지막에 역슬래쉬(\)가 오면, 다음 라인도
//    주석처리 됩니다.

int main(void)
{
    int a = 10;

    // a의 값은 얼마일까요? \
    // a의 값은 얼마일까요? ??/
    ++a;

    printf("%d\n", a);

    return 0;
}
