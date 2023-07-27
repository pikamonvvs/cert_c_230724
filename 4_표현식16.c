// 4_표현식16.c
#include <stdio.h>

// goto 문법은 제한없이 사용될 경우, 코드를 이해하기 어렵게 만듭니다.
// goto는 허용되는 예외적인 상황을 제외하고, goto의 사용을 제한해야 합니다.

// 1) goto 문은 반드시 goto 이후에 선언된 같은 함수의 라벨에 대해서만
//    점프를 수행해야 합니다.
//     => 이후에 수행되는 라벨에 대해서만 허용합니다.

int main(void)
{
    int a = 10;

restart:
    if (a > 0) {
        goto fail; /* OK */
    }

    if (a % 2 == 0) {
        a = 10;
        goto restart; /* NO */
    }

fail:
    return 0;
}
