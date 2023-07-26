
#include <stdio.h>
#include <stddef.h>

struct list_head {
    struct list_head* next;
};

struct user {
    char name[32];
    int age;

    struct list_head link;
};

void insert(struct list_head* head, struct list_head* new)
{
    new->next = head->next;
    head->next = new;
}

#define xoffset_of(s, m) ((unsigned long)&((s*)0)->m)

#if 0
int main(void)
{
    struct user user = { .name = "Tom", .age = 42 };

    // 특정 멤버의 offset을 구하는 방법
    // printf("%zu\n", ((unsigned long)&(*(struct user*)0).link));
    // printf("%zu\n", ((unsigned long)&((struct user*)0)->link));

    printf("%zu\n", xoffset_of(struct user, link));
    return 0;
}
#endif

#if 1
int main(void)
{
    struct user user1 = { .name = "Tom", .age = 42 };
    struct user user2 = { .name = "Bob", .age = 30 };
    struct user user3 = { .name = "Alice", .age = 22 };

    struct list_head head = { .next = NULL };

    insert(&head, &user1.link);
    insert(&head, &user2.link);
    insert(&head, &user3.link);

    struct list_head* cur = head.next;
    while (cur) {
        struct user* p = (struct user*)((char*)cur - offsetof(struct user, link));
        printf("%s(%d)\n", p->name, p->age);

        cur = cur->next;
    }

    return 0;
}
#endif
