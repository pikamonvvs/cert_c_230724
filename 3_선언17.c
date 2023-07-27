// 3_선언17.c
#include <stdio.h>

// 아래 함수가 고정된 개수의 배열을 처리하고 있다면, 효율적인 기계어 코드를 생성하기 위해서
// 컴파일러에게 최소 배열 개수의 정보를 전달할 수 있습니다.

// 아래 함수는 항상 배열이 3개 요소 이상으로 전달됩니다.
// void print_array(int* data, int n)

// 문제점
// 1) 일부 프로세서에서만 지원하는 최적화의 형태입니다.
// 2) 정해진 개수 미만의 데이터를 통해 호출할 경우,
//    "미정의 동작" 입니다.

// => MISRA 에서는 사용을 금지하고 있습니다.
//  : 지원되지 않는 프로세서를 사용하는 경우, 성능향상도 존재하지 않고
//    미세한 성능 향상을 위해 미정의 동작으로 인한 위험성을 감수할 필요가 없습니다.

enum {
    ARRAY_SIZE = 3
};

void print_array(int data[static ARRAY_SIZE], int n)
{
    printf("size: %zu\n", sizeof(data)); // 8

    for (int i = 0; i < n; i++) {
        printf("%d\n", data[i]);
    }
}

int main(void)
{
    int x[3] = { 10, 20, 30 };
    print_array(x, 3);

    int y[2] = { 10, 20 }; /* 미정의 동작 */
    print_array(y, 2);

    return 0;
}
