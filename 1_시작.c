// 1_시작.c

// Compile: Ctrl + F7
// Compile + Linking + Run: Ctrl + F5
#include <stdio.h>

// 1. C11 표준을 기준으로 진행을 합니다.
//   C89, C90
//   C99 - * / MISRA 2012
//   C11 - * / CERT C, MISRA 2023
//   C17

// 2. 시큐어 코딩
//  > 안전한 소프트웨어 개발을 위해서, 소스 코드에 존재할 수 있는
//    잠재적인 보안 취약점을 제거하고, 보안을 고려해서 기능을 설계하고 구현하는
//    행위

// 3. 가이드라인
// - MISRA: Motor Industry Software Reliability Assosiation
//         - MISRA 2012 / 2023
// -  CERT: Computer Emergency Response Team

int main(void)
{
    int n;
    // warning C4996: 'scanf': This function or variable may be unsafe.
    // Consider using scanf_s instead. To disable deprecation,
    // use _CRT_SECURE_NO_WARNINGS. See online help for details.
    // scanf("%d", &n);

    printf("Hello, C\n");
    return 0;
}
