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

#if 0
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
#endif

// * 하나의 반복문 안에 2개 이상의 break / goto 문을 사용하면 안됩니다.
// => 반복문에서 종료 횟수를 제한하는 것은 시각적인 코드의 복잡성을 최소화하는 도움이 됩니다.
#if 0
int main(void)
{
    int state1 = 0;
    int state2 = 42;

    for (int i = 0; i < 10; i++) {
        if (state1) {
            // ..
            break;
        }

        // ...

        if (state2) {
            //...
            break;
        }
    }

    return 0;
}
#endif

#if 0
int main(void)
{
    int state1 = 0;
    int state2 = 42;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {
            if (state1) {
                // ..
                break; /* 내부 루프의 break는 1개이므로 OK */
            }
        }

        if (state2) {
            //...
            break; /* 외부 루프의 break 1개이므로 OK*/
        }
    }

    return 0;
}
#endif

// * 함수는 단일 종료 지점으로 만들어야 합니다.
//  - 함수의 결과를 생성하는 여러 개의 종료 지점이 있는 경우
//    함수의 실행 결과를 예측하기 어렵고, 결과가 처리되지 않는 문제도 발생할 수 있습니다.
#if 0
enum {
    MAX = 10,
};

int f(unsigned int n, char* p)
{
    if (n > MAX) {
        return 0;
    }

    if (p == NULL) {
        return 0;
    }

    // ...

    return 1;
}

int foo(void)
{
}

int main(void)
{
    int result = foo(); /* 미정의 동작 */
    printf("result: %d\n", result);
    return 0;
}
#endif

#if 0
int copy_file(const char* dest, const char* src)
{
    FILE* srcFd = NULL;
    FILE* destFd = NULL;

    int error = 0;

    srcFd = fopen(src, "r");
    if (srcFd != NULL) {
        destFd = fopen(dest, "w");
        if (destFd != NULL) {

            // copy ...

            fclose(srcFd);
            fclose(destFd);
            error = 0;
        } else {
            fclose(srcFd);
            error = 1;
        }

    } else {
        error = 1;
    }

    return error;
}
#endif

// 2) goto
//  => 에러 핸들링
//    : 실패 가능성 있는 함수는 반드시 반환값을 통해 오류를 처리해야 합니다.
int copy_file(const char* dest, const char* src)
{
    FILE* srcFd = NULL;
    FILE* destFd = NULL;

    int error = 0;

    srcFd = fopen(src, "r");
    if (srcFd == NULL) {
        error = 1;
        goto err1;
    }

    destFd = fopen(dest, "w");
    if (destFd == NULL) {
        error = 1;
        goto err2;
    }

    // copy ...
    error = 0;

    fclose(destFd);
err2:
    fclose(srcFd);
err1:
    return error;
}

int main(void)
{
    return 0;
}
