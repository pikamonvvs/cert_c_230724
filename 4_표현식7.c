// 4_표현식7.c
#include <stdio.h>
#include <stddef.h> // offsetof

struct list_head {
    struct list_head* next;
};

struct user {
    char name[32];
    int age;
    // ...
    double height;
    struct list_head link;
};

void insert(struct list_head* head, struct list_head* new)
{
    new->next = head->next;
    head->next = new;
}

#if 0
int main(void)
{
    struct user user1 = {
        .name = "Tom", .age = 42
    };
    struct user user2 = {
        .name = "Bob", .age = 30
    };
    struct user user3 = {
        .name = "Alice", .age = 24
    };

    struct list_head head = { .next = NULL };
    insert(&head, &user1.link);
    insert(&head, &user2.link);
    insert(&head, &user3.link);

    struct list_head* current = head.next;
    while (current) {
        // struct user* 를 통해서 데이터를 출력하기 위해서는
        // 현재 link의 offset을 기준으로 계산이 필요합니다.

        printf("XXX\n");
        current = current->next;
    }

    return 0;
}
#endif

// 구조체 멤버의 오프셋을 구하는 방법
//  - C에서 &* 가 만나면 상쇄됩니다.
//  - (*p).link
//     p->link
#define xoffsetof(s, m) ((unsigned long)&((s*)0)->m)

int main(void)
{
    struct user user1 = {
        .name = "Tom", .age = 42
    };

    // (unsigned long)&(*(struct user*)0).link => link 위치를 참조하는 연산으로 변환됩니다.
    // printf("%lu\n", (unsigned long)&(*(struct user*)0).link);
    // printf("%lu\n", (unsigned long)&((struct user*)0)->link);
    //  => C 표준에서 패딩을 고려한 구조체 멤버의 offset을 구하는 기능을 제공합니다.
    //   : offsetof

    printf("%lu\n", xoffsetof(struct user, link));
    printf("%lu\n", offsetof(struct user, link));

    return 0;
}
