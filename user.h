// user.h

#ifndef USER_H
#define USER_H

struct user;

typedef struct user USER;

extern USER* get_current_user(void);
extern void print_user(const USER* user);

#endif
