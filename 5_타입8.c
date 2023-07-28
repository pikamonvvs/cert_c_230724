// 5_타입8.c
#include <stdio.h>
#include <stdlib.h>

// 핵심: 신뢰할 수 없는 소스로부터의 데이터는
//      반드시 검사해야 합니다.

// => 상한값과 하한값을 체크해야 합니다.
#if 0
int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "./a.out [table_size]\n");
        return 1;
    }

    int table_size = atoi(argv[1]);
    int* table = malloc(sizeof(int) * table_size);
    if (table != NULL) {
        // ...
    }

    return 0;
}
#endif

#if 0
enum {
    MIN_TABLE_SIZE = 1,
    MAX_TABLE_SIZE = 32
};

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "./a.out [table_size]\n");
        return 1;
    }

    int table_size = atoi(argv[1]);

    if (table_size <= MAX_TABLE_SIZE && table_size >= MIN_TABLE_SIZE) {
        int* table = malloc(sizeof(int) * table_size);
        if (table != NULL) {
            // ...
        }
    } else {
        printf("잘못된 데이터가 입력되었습니다.\n");
    }

    return 0;
}
#endif

// 1) scanf
//  - 정수의 서식에 대한 입력에서, 오류를 제대로 처리하지 못하는 문제가 있습니다.
//  - 표현범위를 넘어서는 데이터에 대해서는 제대로 처리하지 못하는 문제가 있습니다.
#if 0
int main(void)
{
    int n;
    int ret;

    ret = scanf("%d", &n);

    // 입력이 제대로 수행되었는지 검사가 필요합니다.
    if (ret == 1) {
        printf("%d\n", n);
    } else {
        printf("잘못된 입력입니다..\n");
    }

    return 0;
}
#endif

// - 사용자로부터 문자열을 입력 받아서, 정수로 변환해서 사용하면 됩니다.
//  => 입력의 길이가 지정된 버퍼를 넘어설 경우,
//     미정의 동작이 발생합니다.
//  => Linux의 scanf는 허용된 데이터의 길이가 초과된 경우,
//     ERANGE, errno를 통해 오류를 전달하지만, 표준이 아닙니다.

#if 0
int main(void)
{
    char buf[32];
    int n;
    int ret;

    ret = scanf("%s", buf);

    if (ret == 1) {
        n = atoi(buf);
        printf("%d\n", n);
    } else {
        printf("잘못된 입력입니다..\n");
    }

    return 0;
}
#endif

// 해결 방법
//  => 문자열을 입력받을 때, 버퍼의 길이를 지정할 수 있는 표준함수를
//     사용해야 합니다.
//     : fgets
#if 0
int main(void)
{
    char buf[32];
    fgets(buf, sizeof buf, stdin);

    printf("buf: %s\n", buf);

    int n = atoi(buf); /* atoi 계열의 함수는 사용하지 말아야 합니다. */
    printf("%d\n", n);

    return 0;
}
#endif

// * atoi 계열 함수의 문제점
// 1) 정수와 문자가 섞여 있는 데이터에서
//    정수만을 변환하는 형태로 잘못된 데이터를 감지하지 못합니다.
// 2) 잘못된 결과와 0을 구분할 수 없습니다.
// => 미정의 동작
// => strtol 계열의 함수를 사용해야 합니다.
//  : strtol
//    strtoll => long long, C99
//    strtoul
//    strtoull => C99

#if 0
int main(void)
{
    char* str = "asdsa";

    int result = atoi(str);
    printf("result: %d\n", result);

    return 0;
}
#endif

#include <errno.h>
// strtol 계열의 함수는 오류가 발생하였을 경우,
// errno를 통해 오류의 원인을 파악할 수 있습니다.

int main(void)
{
    char buf[32];

    errno = 0;
    fgets(buf, sizeof(buf), stdin);
    if (errno == 0) {
        // 문자열을 정수로 변환하면서, 문자열의 어느 지점까지 사용했는지
        // 위치 정보를 담는 목적으로 제공합니다.
        char* end_ptr;
        long data;

        errno = 0;
        data = strtol(buf, &end_ptr, 10);
        if (errno == ERANGE) {
            perror("ERANGE\n"); // 표현 범위를 넘어선 문자열이 전달될 경우
        } else if (errno == EINVAL) {
            perror("EINVAL\n"); // 잘못된 데이터가 전달된 경우
        } else if (*end_ptr != '\0' && *end_ptr != '\n') {
            printf("잘못된 문자열이 존재합니다..\n");
        } else {
            printf("%ld\n", data);
        }
    } else {
        printf("입력이 제대로 처리되지 않았습니다...\n");
    }

    return 0;
}
