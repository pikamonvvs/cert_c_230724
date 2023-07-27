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

#define container_of(ptr, s, m) \
    (s*)((char*)ptr - offsetof(s, m))

#if 1
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
        // => 1바이트 단위 연산을 포인터의 산술연산에서 수행하기 위해서는
        //    (char*)로 캐스팅이 필요합니다.
        // struct user* p = (struct user*)((char*)current - offsetof(struct user, link));
        struct user* p = container_of(current, struct user, link);
        printf("%s(%d) -> ", p->name, p->age);

        current = current->next;
    }
    printf("<null>\n");

    return 0;
}
#endif

#if 0
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
    //    stddef.h
    //   : offsetof

    printf("%lu\n", xoffsetof(struct user, link));
    printf("%lu\n", offsetof(struct user, link));

    return 0;
}
#endif
