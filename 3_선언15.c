// 3_선언15.c
#include <stdio.h>
#include <signal.h>

// signal
// void (*signal(int sig, void (*func)(int)))(int);

// 1) signal(int sig, void (*func)(int))
//  => signal은 함수입니다. 반환 타입은?

// 2) (*signal(int sig, void (*func)(int)))
//  => signal 함수의 반환 타입은 포인터입니다. 포인터가 참조하는 타입은?

// 3) (*signal(int sig, void (*func)(int)))(int)
//  => 포인터가 참조하는 타입은 함수입니다. 반환 타입은?

// 4) void (*signal(int sig, void (*func)(int)))(int);
//  => 반환 타입은 void 입니다.

//  typedef void (*sig_t) (int);
//  sig_t signal(int sig, sig_t func);

/*
SIGNAL
 => SIGINT: Ctrl + C
   SIGQUIT: Ctrl + \
*/

// volatile 제한자

int flag = 1;

void handler(int signum)
{
    printf("handler: %d\n", signum);
    flag = 0;
}

void process(void)
{
    while (flag) {
        // ...
    }

    printf("process end\n");
}

int main(void)
{
    signal(SIGINT, handler);
    process();

    printf("main end\n");

    return 0;
}

#if 0
void handler(int signum)
{
    printf("signal: %d\n", signum);
}

int main(void)
{
    signal(SIGINT, handler);

    getchar();

    return 0;
}
#endif
