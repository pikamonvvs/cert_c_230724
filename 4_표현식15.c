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
