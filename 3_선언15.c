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

// * 메모리 가시성 문제
//  > CPU는 성능상의 이유로 변수의 값을 읽을 때, 항상 메모리를 참조하지 않습니다.
//    다른 컨텍스트에서 변경된 데이터 또는 하드웨어의 신호(인터럽트)에 의해서 변경된 메모리의 변경 ㅅ ㅏ항을
//    제대로 관찰할 수 없습니다.
// * 해결 방법
//  > 변수의 값을 반드시 메모리로부터 읽어 오도록 한정자를 지정해야 합니다.
//    "volatile"
//    - volatile 한정자는 프로그램이 아닌 외부적인 요소에 의해 값의 변경이 발생할 수 있음을
//      컴파일러에게 알려주는 키워드입니다.

//       flag=1         flag=1
//  CPU [Cache]  ------- [Mem]

//      flag=1           flag=0
//  CPU [Cache]  ------- [Mem] <-- SIGINT

volatile int flag = 1;
// flag라는 변수를 참조할 때는 반드시 메모리로부터 읽어와야 합니다.
// => volatile

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
