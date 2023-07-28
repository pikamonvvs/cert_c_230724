// 5_타입9.c
#include <stdio.h>
#include <limits.h>

// 문제점
// 1) index + 1 연산에서 Overflow 미정의 동작의 가능성이 있습니다.
// 2) 음수가 전달될 경우, 결과로 음수가 나오고,
//    유효하지 않은 메모리에 대한 접근으로 미정의 동작이 발생할 수 있습니다.

// 정수 나누기 / 나머지
// 1) C99 이전에는 음수 피연산자에 대한 나누기, 나머지 연산의 부호가 미지정 동작이었습니다.
// 2) C99 표준 이후로 다음과 같이 표준이 결정되었습니다.
//  - 나눗셈 연산의 결과는 첫번째 피연산자를 두번째 피연산자로 나눈 몫입니다.
//  - 나머지 연산의 결과는 나머지 입니다.
//  - 두 연산에서 두번째 값이 0인 경우, 미정의 동작이 발생합니다.
//  - 정수가 나누어질 때, 나누기 연산의 결과는 수학적인 몫으로 소수점 이하는 버려집니다.
//  - 결과의 부호는 첫번째 피 연산자의 부호를 따릅니다.
//  => A/B * B + (A%B) => A가 되는 것이 보장됩니다.

#if 0
int insert(int index, int* list, int size, int value)
{
    int ret = -1;
    if (size != 0) {
        index = (index + 1) % size;

        list[index] = value;
        ret = index;
    }

    return ret;
}
#endif

// 해결 방법
// 1) 경계 체크를 해야합니다.
#if 0
int insert(int index, int* list, int size, int value)
{
    int ret = -1;
    if (size != 0 && (index >= 0 && index < size)) {
        index = (index + 1) % size;

        list[index] = value;
        ret = index;
    }

    return ret;
}
#endif

// 2) 타입을 정확하게 설계해야 합니다.
//  => 길이와 크기를 표현하는 타입에 대해서는 부호 없는(unsigned)를 사용해야 합니다.
//  => unsigned int
//   : size_t
int insert(size_t index, int* list, int size, int value)
{
    int ret = -1;

    // 경계를 체크하는 로직을 좀더 간단하게 구현할 수 있습니다.
    if (size != 0 && index < size) {
        index = (index + 1) % size;

        list[index] = value;
        ret = index;
    }

    return ret;
}

int main(void)
{
    int data[32] = { 0 };
    int ret;
    // ret = insert(INT_MAX, data, sizeof data, 42);

    ret = insert(-42, data, sizeof data, 42);
    printf("ret: %d\n", ret);

    return 0;
}
