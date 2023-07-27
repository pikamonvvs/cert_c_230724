// 4_표현식16.c
#include <stdio.h>

// goto 문법은 제한없이 사용될 경우, 코드를 이해하기 어렵게 만듭니다.
// goto는 허용되는 예외적인 상황을 제외하고, goto의 사용을 제한해야 합니다.

// 1) goto 문은 반드시 goto 이후에 선언된 같은 함수의 라벨에 대해서만
//    점프를 수행해야 합니다.
//     => 이후에 수행되는 라벨에 대해서만 허용합니다.
#if 0
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
#endif

// goto가 유용할 때
// 1) 중첩된 반복문을 탈출할 때, flag를 사용하는 것보다
//    goto 사용하는 것이 유용할 수 있습니다.

#if 0
int main(void)
{
    int n = 5;
    int flag = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {

            if (i + j == n) {
                // 전체 루프를 탈출하고 싶습니다.
                printf("---- break ----\n");
                flag = 1;
                break;
            }
        }

        if (flag) {
            break;
        }
    }

    return 0;
}
#endif

int main(void)
{
    int n = 5;
    int flag = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {

            if (i + j == n) {
                printf("---- goto ----\n");
                goto out;
            }
        }
    }
out:

    return 0;
}
