// 3_선언5.c
#include <stdio.h>
#include <assert.h>

// 1) 구조체의 크기는 플랫폼에 따라 달라질 수 있습니다.
// 2) 구조체를 통해 파일에 저장하거나, 데이터의 교환을 목적으로 사용할 경우,
//    패딩을 제거하는 형태로 사용해야 합니다.

#pragma pack(1) // 컴파일러 확장 명령

struct packet {
    unsigned char cmd;
    int len;
    // ...
};

void process(struct packet* packet)
{
    // 반드시 구조체의 크기가 5이어여 합니다.
    assert(sizeof(struct packet) == 5);

    printf("process\n");
}

int main(void)
{
    printf("size: %zu\n", sizeof(struct packet));

    struct packet packet = { 0 };
    process(&packet);

    return 0;
}
