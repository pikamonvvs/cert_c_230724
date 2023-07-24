// 1_시작.c

// Compile: Ctrl + F7
// Compile + Linking + Run: Ctrl + F5

#include <stdio.h>

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
