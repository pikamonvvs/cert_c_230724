// 4_표현식6.c
#include <stdio.h>
#include <string.h> // memcmp

struct s {
    char c;
    int i;

    char buffer[13];
};

// 구조체를 비교하는 함수를 만들고 싶습니다.
//  - 문제점: 패딩도 비교의 대상으로 사용하고 있습니다.
//          구조체 패딩이 어떤 값을 가지고 있는지는 미지정 사항입니다.
//  - 해결 방법
//   => 각 멤버를 비교하는 형태로 구현해야 합니다.
#if 0
int compare(const struct s* left, const struct s* right)
{
    int result = 0;
    if (left != NULL && right != NULL) {
        result = memcmp(left, right, sizeof(struct s)) == 0;
    }

    return result;
}
#endif

#if 1
// 구조체 패딩의 영향을 받지 않도록,
// 각 멤버를 기반으로 비교를 수행해야 합니다.
int compare(const struct s* left, const struct s* right)
{
    int result = 0;
    if (left != NULL && right != NULL) {
        result = (left->c == right->c) && (left->i == right->i) && (memcmp(left->buffer, right->buffer, sizeof(left->buffer)) == 0);
    }

    return result;
}
#endif

int main(void)
{
    struct s s1 = { .c = 'A', .i = 42 }; // 패딩도 0으로 초기화됩니다.
    // struct s s2 = { .c = 'A', .i = 42 };

    struct s s2; // 패딩의 값은 알 수 없습니다.
    s2.c = 'A';
    s2.i = 42;
    memset(s2.buffer, 0, sizeof(s2.buffer));

    int equal = compare(&s1, &s2);
    printf("equal: %d\n", equal);

    return 0;
}
