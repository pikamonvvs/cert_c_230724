// 3_선언.c
#include <stdio.h>

struct user {
    char name[32];
    int age;
    // ...
    char address[100];
};

// 1. 구조체를 함수의 인자로 전달할 때, call by value를 사용하는 것은
//    복사의 비용이 비효율적입니다.
//  => 포인터를 이용해서 주소를 전달합니다.
#if 0
void PrintUser(struct user user)
{
    printf("%s(%d)\n", user.name, user.age);
}

int main(void)
{
    printf("%zu\n", sizeof(struct user));
    struct user u1 = { .name = "Tom", .age = 42 };

    PrintUser(u1);

    return 0;
}
#endif

#if 0
// 2. 구조체를 함수의 인자로 주소를 전달 할때,
//    값을 변경하지 않는다면, 반드시 const를 사용해야 합니다.
void PrintUser(const struct user* user)
{
    // printf("%s(%d)\n", (*user).name, (*user).age);
    printf("%s(%d)\n", user->name, user->age);
    // user->age = 100;
}

// 불변성(Immutable)을 지향해야 합니다.
// => 생성 이후에 값을 변경하지 않습니다.
//  : 불변성은 애플리케이션의 정확성과 안정성을 보장하는데 도움이 됩니다.
// 1) 동시성 프로그래밍에서 동기화 이슈가 발생하지 않습니다.
// 2) 참조 계수 등의 자원 공유 모델을 쉽게 구현할 수 있습니다.
// 3) 대상체의 값이 변경되는 경로를 쉽게 추적할 수 있습니다.

int main(void)
{
    printf("%zu\n", sizeof(struct user));
    struct user u1 = { .name = "Tom", .age = 42 };
    PrintUser(&u1);

    const struct user u2 = { .name = "Tom", .age = 42 }; /* 불변성 */

    return 0;
}
#endif

#if 1
#include <string.h>
// strchr
//  : char *strchr(const char *s, int c);

int main(void)
{
    // char* s1 = "hello";
    const char* s1 = "hello";
    // 문자열 리터럴은 읽기 전용 메모리에 존재합니다.
    // => 문자열 리터럴을 참조할 때는 반드시 const char*를 사용해야 합니다.

    // s1[0] = 'x'; /* 미정의 동작 */

    // char* p = strchr(s1, 'e');
    const char* p = strchr(s1, 'e');
    // 수정이 불가능한 문자열 리터럴을 제공한 경우, 반환을 const char*로 받아야 합니다.

    if (p != NULL) {
        // *p = 'x'; /* 미정의 동작 */
        printf("%c\n", *p);
    }

    return 0;
}
#endif
