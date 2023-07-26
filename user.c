// user.c
#include "user.h"

#include <stdio.h>

struct user {
    char name[32];
    char password[32];
};

USER current = {
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
