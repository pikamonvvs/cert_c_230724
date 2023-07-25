// 3_선언6.c
#include <stdio.h>

enum {
    ARRAY_SIZE = 10
};

void init_array(int** ptr_param)
{
    int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }

    *ptr_param = arr;
}

int main(void)
{
    int* ptr;
    init_array(&ptr);

    return 0;
}
