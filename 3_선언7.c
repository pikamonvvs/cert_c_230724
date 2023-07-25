// 3_선언7.c
#include <stdio.h>

#if 0
struct point {
    int x;
    int y;
};

struct point add(struct point pt1, struct point pt2)
{
    struct point result = { .x = pt1.x + pt2.x, .y = pt1.y + pt2.y };
    return result;
}

void print_point(struct point pt)
{
    printf("(%d, %d)\n", pt.x, pt.y);
}

int main(void)
{
    struct point pt1 = { .x = 10, .y = 20 };
    struct point pt2 = { .x = 100, .y = 200 };

    struct point result = add(pt1, pt2);
    print_point(result);

    return 0;
}
#endif

#if 0
struct point {
    int x;
    int y;

    int temp[100];
};

struct point add(const struct point* pt1, const struct point* pt2)
{
    struct point result = {
        .x = pt1->x + pt2->x,
        .y = pt1->y + pt2->y,
    };

    return result;
    // 구조체를 함수에서 반환할 때, 값으로 반환하면 복사 오버헤드가 있습니다.
}

void print_point(const struct point* pt)
{
    printf("(%d, %d)\n", pt->x, pt->y);
}

int main(void)
{
    struct point pt1 = { .x = 10, .y = 20 };
    struct point pt2 = { .x = 100, .y = 200 };

    struct point result = add(&pt1, &pt2);
    print_point(&result);

    return 0;
}
#endif

struct point {
    int x;
    int y;

    int temp[100];
};

void print_point(const struct point* pt)
{
    printf("(%d, %d)\n", pt->x, pt->y);
}

// 1) 지역 변수 반환 => 사라지는 메모리에 대한 참조 "미정의 동작"
// 2) 정적 변수 반환 => 재진입 불가능한 함수
// 3) 동적 메모리 반환 => 누수 위험성, 할당 오버헤드
// 4) Out Parameter
//   => 결과를 인자를 통해 전달 받는 방법

#if 0
struct point* add(const struct point* pt1, const struct point* pt2)
{
    // static struct point result;
    struct point* result = malloc(sizeof(struct point));

    result->x = pt1->x + pt2->x;
    result->y = pt2->x + pt2->y;

    return &result;
}
#endif

#if 0
// 사용자 정의 타입을 처리하는 일반적인 함수의 형태
void add(const struct point* pt1, const struct point* pt2,
    struct point* result)
{
    result->x = pt1->x + pt2->x;
    result->y = pt1->y + pt2->y;
}

int main(void)
{
    struct point pt1 = { .x = 10, .y = 20 };
    struct point pt2 = { .x = 100, .y = 200 };

    // struct point result = add(&pt1, &pt2);
    // print_point(&result);

    struct point result;
    add2(&pt1, &pt2, &result);

    print_point(&result);

    return 0;
}
#endif

#if 1
// C 에서 파라미터는 지역 변수와 동일하게 취급됩니다.
int add2(int a, int b)
{
    // => 함수로 전달된 파라미터를 변경하는 행위는 안됩니다.
    // a = 10; // NO
    // b = 20; // NO
    int ra = a;

    return a + b;
}

int main(void)
{
    int a = 10;
    int b = 20;

    int result = add2(a, b);
}
#endif
