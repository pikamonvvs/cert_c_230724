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
