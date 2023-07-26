// user.c
#include "user.h"

#include <stdio.h>

struct user {
    char name[32];
    char password[32];
};

// 전역 변수는 함수를 통해 상태를 접근하도록 제어하는 것이
// 좋습니다.
// => static, Internal linkage
static USER current = {
    .name = "admin",
    .password = "admin_password",
};

USER* get_current_user(void)
{
    return &current;
}

void print_user(const USER* user)
{
    printf("User: %s\n", user->name);
}
