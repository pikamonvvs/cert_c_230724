// 3_선언9.c
#include <stdio.h>

// Out Parameter를 통해서 결과를 전달 받는 함수입니다.
// 1. 입력된 인자가 유효한지 판단이 필요합니다.
#if 0
void divide(int divided, int divisor, int* result)
{
    if (divisor != 0 && result != NULL) {
        *result = divided / divisor;
    }
}

#endif
// 2. 함수의 반환값을 통해서 함수가 성공했는지 여부를 반환할 수 있습니다.
// => MISRA 에서는 함수의 반환 경로는 1개만 존재해야 합니다.
#if 0
int divide(int divided, int divisor, int* result)
{
    int error = 0;
    if (divisor == 0) {
        error = -100;
    } else if (result == NULL) {
        error = -200;
    } else {
        *result = divided / divisor;
    }

    return error;
}

// 3. 함수의 성공/실패가 반환값을 통해 전달될 경우,
//    반드시 함수의 오류 여부를 체크해야 합니다.
int main(void)
{
    int data = 0;
    // int error = divide(10, 4, &data);
    int error = divide(10, 0, &data); /* 미정의 동작 */
    // divide(10, 4, NULL); /* 미정의 동작 */
    if (error == 0) {
        printf("%d\n", data);
    } else {
        printf("error: %d\n", error);
    }

    return 0;
}
#endif

// int divide(int divided, int divisor, int* result)
//  문제점
//   - 반환 타입의 정보만으로는 함수가 결과를 반환하는지,
//     오류를 반환하는지 구분하기 어렵습니다.
//  해결 방법
//   - 에러를 반환하는 함수는 함수의 반환 타입을 에러 타입으로 사용하는 것이 좋습니다.
//   - 에러 코드도 매직 넘버가 아닌 심볼릭 상수를 사용하는 것이 좋습니다.
#if 1
typedef int error_t;
enum {
    DIVISION_BY_ZERO = -100,
    INVALID_POINTER = -200
};

error_t divide(int divided, int divisor, int* result)
{
    error_t error = 0;
    if (divisor == 0) {
        error = DIVISION_BY_ZERO;
    } else if (result == NULL) {
        error = INVALID_POINTER;
    } else {
        *result = divided / divisor;
    }

    return error;
}

// 3. 함수의 성공/실패가 반환값을 통해 전달될 경우,
//    반드시 함수의 오류 여부를 체크해야 합니다.
int main(void)
{
    int data = 0;

    error_t error = divide(10, 0, &data);
    // divide(10, 4, NULL);
    if (error == 0) {
        printf("%d\n", data);
    } else {
        printf("error: %d\n", error);
    }

    return 0;
}
#endif

#if 0
// 1. errno 전역 변수를 통해 에러의 원인을 파악할 수 있습니다.
#include <errno.h>

// 2. errno를 문자열로 변경하는 기능을 제공합니다. - strerror
#include <string.h>

// 3. perror() 함수를 통해 위의 과정을 수행할 수 있습니다.
// #include <stdio.h>

int main(void)
{
    FILE* fp = fopen("a.txt", "r");
    if (fp == NULL) {
        // fprintf(stderr, "fopen() error: %d\n", errno);
        // fprintf(stderr, "fopen() error: %s\n", strerror(errno));
        perror("fopen() error");
        return 1;
    }

    return 0;
}
#endif

// scanf_s, strcpy_s ....
// => C11 Annex K 확장 라이브러리
// => 표준에 도입이 되었지만, 강제되지 않습니다.
// => 오직 윈도우 컴파일러만 지원하고 있습니다.

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[10];

    // 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead
    // strcpy(buf, "helloworld"); /* 미정의 동작 */

    errno_t error;
    error = strcpy_s(buf, sizeof buf, "heellworld");
    printf("error: %d\n", error);
    // printf("%s\n", buf);

    return 0;
}
#endif
