// 5_타입.c
#include <stdio.h>

// 1. 사용하는 아키텍처의 데이터 모델에 대해서 제대로 이해해야 합니다.
//    데이터 모델은 표준 데이터 타입에 할당되는 크기를 정의합니다.

// 2. 아키텍처와 컴파일러의 종류에 따라서 기본 타입의 크기가 다릅니다.
//    C 표준에서 정의하고 있는 타입의 크기는 char는 1바이트 입니다.

// 3. 표준 타입을 바로 사용하면 안됩니다.
//    => 표준 타입을 사용할 때, <stdint.h> 헤더를 통해 제공되는 타입 정의를
//       이용해야 합니다. : C99 표준
#include <stdint.h>
//   - 조건부 컴파일 통해 typedef가 구현되어 있습니다.

// 4. 부동 소수점 타입에 대해서는 제공되지 않습니다.
//    직접 typedef 를 통해 제공해야 합니다.
typedef float float32_t;
typedef double float64_t;

int main(void)
{
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(long double)); // 8? 16?

    int8_t a; // 8비트의 부호 있는 정수 - 1바이트 정수
    int16_t b;

    uint8_t c; // 8비트의 부호 없는 정수
    uint16_t d;

    int_least16_t e; // 플랫폼에서 지원하는 최소 16비트의 부호 있는 정수 타입
    int_fast32_t f; // 플랫폼에서 지원하는 가장 빠른 타입 중 32비트 부호 있는 정수 타입

    return 0;
}
