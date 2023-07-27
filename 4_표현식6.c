// 4_표현식6.c
#include <stdio.h>
#include <string.h> // memcmp

struct s {
    char c;
    int i;

    char buffer[13];
};

// 구조체를 비교하는 함수를 만들고 싶습니다.
int compare(const struct s* left, const struct s* right)
{
    int result = 0;
    if (left != NULL && right != NULL) {
        result = memcmp(left, right, sizeof(struct s)) == 0;
    }

    return result;
}

int main(void)
{
    struct s s1 = { .c = 'A', .i = 42 };
    struct s s2 = { .c = 'A', .i = 42 };

    int equal = compare(&s1, &s2);
    printf("equal: %d\n", equal);

    return 0;
}
