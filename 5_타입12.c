// 5_타입12.c
#include <stdio.h>

#if 0

float mean(float* arr, size_t len)
{
    float total = .0f;

    for (size_t i = 0; i < len; i++) {
        total += arr[i];
    }

    return (len == 0) ? 0 : total / len;
}

int main(void)
{
    float arr[10];
    for (size_t i = 0; i < 10; i++) {
        arr[i] = 10.1f;
    }

    float result = mean(arr, 10);
    printf("result: %f\n", result);

    return 0;
}
#endif

// 정확한 계산이 필요하면, 소수점을 배제해서 사용할 수 있는 지를 고려해야 합니다.
float mean(float* arr, size_t len)
{
    float total = .0f;

    for (size_t i = 0; i < len; i++) {
        total += arr[i];
    }

    return (len == 0) ? 0 : total / len;
}

int main(void)
{
    float arr[10];
    for (size_t i = 0; i < 10; i++) {
        arr[i] = 10.1f * 1000; /* 핵심 */
    }

    float result = mean(arr, 10);
    printf("result: %f\n", result / 1000); /* 핵심 */

    return 0;
}
