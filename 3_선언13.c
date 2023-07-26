// 3_선언13.c
#include <stdio.h>

#include "user.h"

int main(void)
{
    USER* user = get_current_user();
    print_user(user);

    return 0;
}
