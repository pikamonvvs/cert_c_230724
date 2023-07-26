// 3_선언14.c
#include <stdio.h>
#include <string.h>

void print_data(int* data, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%2d ", data[i]);
    }
    printf("\n");
}

int main(void)
{
    int data[10] = { 1, 2, 3, 4, 5 };
    print_data(data, 10);

    memcpy(data + 1, data, sizeof(int) * 5);
    print_data(data, 10);

    return 0;
}
