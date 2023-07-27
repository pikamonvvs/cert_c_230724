// 4_표현식5.c
#include <stdio.h>

// 1) 구조체가 멤버가 아무것도 존재하지 않을 경우,
//    사이즈는 0 입니다.
//   => C에서는 비어있는 구조체는 미정의 사항입니다.
//   => C++은 가능합니다. Empty Object

#if 0
struct AAA {
};
#endif

// 2) C 표준에서 구조체는 멤버를 1개 이상 제공해야 합니다.
// 3) 구조체의 크기는 멤버 변수의 총합과 일치하지 않을 수 있습니다.

// * C 표준
// - 구조체 내부에 이름없는 패딩(접근이 불가능한)이 포함될 수 있으며, 앞쪽에는 패딩이 존재하지 않습니다.
//   중간과 마지막에는 패딩이 존재할 수 있습니다.

// - CPU가 구조체의 멤버에 접근하는 것을 효율적으로 수행하기 위해서 패딩이 필요합니다.

// - 구조체의 패딩이 어떤 형태로 생성되는지, 미지정 동작입니다.
//   => 컴파일러, 실행 환경에 따라 패딩이 달라질 수 있습니다.

#if 0
struct AAA {
    int n;
    // char __padding1[4];
    double d;
    char c;
    // char __padding2[7];
};

struct BBB {
    int n;
    char c;
    double d;
};
// => 멤버 변수의 배치 순서에 따라, 패딩을 조절할 수 있습니다.
//    제한된 메모리 환경에서는 유용합니다.

int main(void)
{
    printf("%zu\n", sizeof(struct AAA));
    printf("%zu\n", sizeof(struct BBB));
    return 0;
}
#endif

#if 0
     size_t
     fread(void *restrict ptr, size_t size, size_t nitems,
         FILE *restrict stream);

     size_t
     fwrite(const void *restrict ptr, size_t size, size_t nitems,
         FILE *restrict stream);
#endif

// * 구조체를 파일로 저장하거나, 구조체를 네트워크로 전송하는 목적으로 사용할 때,
//   플랫폼에 따라 패딩이 달라질 수 있습니다.
//  => 패딩을 제거해야 합니다.
//    "컴파일러 확장 명령을 통해 수행해야 합니다."

// #pragma pack(1)
// MSVC
#if 0
#pragma pack(push, 1) // MSVC, GCC, clang
struct user {
    char name[10];
    double height;
    int age;
    double weight;
};
#pragma pack(pop)
#endif

#if 0
struct user {
    char name[10];
    double height;
    int age;
    double weight;
} __attribute__((packed));
#endif

// GCC
#if 0

struct AAA {
    int n;
    double c;
};

void save(struct user* users, int n)
{
    FILE* fp = fopen("users.dat", "w");
    if (fp == NULL) {
        return;
    }

    fwrite(users, sizeof(struct user), n, fp);
    fclose(fp);
}

int main(void)
{
    printf("%zu\n", sizeof(struct user));
    printf("%zu\n", sizeof(struct AAA));

    struct user users[3] = {
        { .name = "Tom", .age = 42, .weight = .5, .height = .2 },
        { .name = "Bob", .age = 15, .weight = .2, .height = .8 },
        { .name = "Alice", .age = 22, .weight = .2, .height = .8 },
    };

    save(users, 3);

    return 0;
}
#endif

#pragma pack(2)

#if 1
struct AAA {
    int n;
    double d;
    char c;
}; // __attribute__((packed, aligned(2)));

int main(void)
{
    printf("%zu\n", sizeof(struct AAA));

    return 0;
}
#endif
