// user.h

#ifndef USER_H
#define USER_H

#include <stdio.h>

struct user;

typedef struct user USER;

extern USER* get_current_user(void);
extern void print_user(const USER* user);

// 외부에서 호출이 가능한 inline 함수의 경우 헤더를 통해서 제공해야 합니다.
// : 구조체의 멤버에 접근하는 함수의 경우,
//   불투명한 타입을 통해서는 구현이 불가능합니다.

#endif
