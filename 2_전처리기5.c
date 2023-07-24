// 2_전처리기5.c
#include <stdio.h>

int operations = 0; /* 전체 함수 호출 횟수 */
int calls_to_f = 0; /* F() 함수 호출 횟수 */
int calls_to_g = 0; /* G() 함수 호출 횟수 */

#define F(x) (++operations, ++calls_to_f, 2 * (x))
#define G(x) (++operations, ++calls_to_g, (x) + 1)

int main(void)
{
    int result;
    int x = 10;

    result = F(x) + G(x);

    printf("result: %d\n", result);
    printf("%d %d %d\n", operations, calls_to_f, calls_to_g);

    return 0;
}
