// 4_표현식15.c
#include <stdio.h>

// 제어문(Control Statement)
// - if, switch, while, for, do-while

// 1) if, for, while
//  => 문장이 하나만 존재하더라도, 반드시 중괄호를 사용해야 합니다.
//  => 매달리는 else의 문제를 방지하기 위해서
#if 0
enum {
    GUEST,
    ADMIN
};

int is_user_login(void) { return 1; }
int is_guest(void) { return 1; }

int main(void)
{
    int level;
    if (is_user_login()) {
        if (is_guest())
            level = GUEST;
    } else {
        level = ADMIN;
    }

    return 0;
}
#endif

#if 0
// 2) if, else-if 구조에서는 반드시 else를 사용해야 합니다.
enum {
    GUEST,
    USER,
    ADMIN
};

int is_user_login(void) { return 1; }
int is_guest(void) { return 1; }

int main(void)
{
#if 0
    int level = ADMIN;
    if (is_user_login()) {
        level = USER;
    } else if (is_guest()) {
        level = GUEST;
    }
#endif

    // 해결 방법 1.
#if 0
    int level;
    if (is_user_login()) {
        level = USER;
    } else if (is_guest()) {
        level = GUEST;
    } else {
        level = ADMIN;
    }
#endif

    // 해결 방법 2.
    int level = ADMIN;
    if (is_user_login()) {
        level = USER;
    } else if (is_guest()) {
        level = GUEST;
    } else {
        ; // ;을 통해 의도되었다. => Optional
        /* Nothing */
    }

    // 단일 if 에서는 else가 강제되지 않습니다.
    if (is_user_login()) { /* OK */
        // ...
    }

    return 0;
}
#endif

// Switch
// => 1) 반드시 break를 작성해야 합니다.
//    2) 의도적으로 break를 제외하는 경우, case 라벨 안에서
//       아무것도 수행하면 안됩니다.
//    3) default를 반드시 작성해야 합니다.
//    4) default의 위치는 제일 위와 아래만 허용합니다.

enum {
    GUEST,
    USER,
    ADMIN
};

int main(void)
{
    int level = GUEST;

/* NO */
#if 0
    switch (level) {
    case GUEST:
        printf("guest\n");
    case USER:
        printf("user\n");
        break;
    case ADMIN:
        break;
    }
#endif

#if 0
    switch (level) {
    case GUEST: // 아무일도 수행하지 않기 때문에 break를 의도적으로 사용하지 않는 것을 허용합니다.
    case USER:
        printf("user\n");
        break;
    case ADMIN:
        break;
    default:
        break; // default에 break가 반드시 제공되어야 합니다.
    }
#endif

    switch (level) {
    default:
        break; /* OK - 가장 위도 허용합니다. */

    case GUEST:
    case USER:
        printf("user\n");
        break;

    case ADMIN:
        break;
    }

    return 0;
}
