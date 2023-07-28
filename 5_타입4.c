// 5_타입4.c
#include <stdio.h>

// * char 타입
//  char: 문자열 리터럴의 각 요소를 구성하는 타입입니다.
//   "문자 타입"
//  => signed / unsigned 미지정 사항입니다.

// *         char: 문자 타입
//    signed char: 부호 있는 8비트 정수 타입
//  unsinged char: 부호 없는 8비트 정수 타입

int main(void)
{
    signed char str1[] = "hello"; /* NO! */
    printf("%s\n", str1);

    unsigned char str2[] = "hello"; /* NO! */
    printf("%s\n", str2);

    char str3[] = "hello"; /* 문자 타입은 반드시 char를 사용해야 합니다. */
    printf("%s\n", str3);

    char n = 42; /* NO!, unsigned, signed 인지 미지정 동작 */

    // 8비트 정수 타입을 목적으로 사용할 때는 반드시 부호(signed, unsigned) 유무를 명시해야
    // 합니다.
    signed char n2 = 42; /* OK */
    unsigned char n3 = 42; /* OK */

    return 0;
}
