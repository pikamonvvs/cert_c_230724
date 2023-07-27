// 4_표현식7.c
#include <stdio.h>

struct list_head {
    struct list_head* next;
};

struct user {
    char name[32];
    int age;
    // ...

    struct list_head link;
};

void insert(struct list_head* head, struct list_head* new)
{
    new->next = head->next;
    head->next = new;
}

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
        printf("XXX\n");
        current = current->next;
    }

    return 0;
}
