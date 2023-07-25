// 2_전처리기12.c
#include <stdio.h>

// 미리 정의된 매크로(predefined macro)
// 1) __FILE__: 현재 소스 파일명
// 2) __LINE__: 소스 코드 라인     => 매크로 함수를 통해서 처리해야 합니다.
// 3) __DATE__: 소스를 컴파일한 날짜
// 4) __TIME__: 소스를 컴파일한 시간

// __func__
// => 현재 함수의 이름으로 처리되는 문자열 상수(const char*)

// 5) __STDC__: 컴파일러가 표준을 지원하는지 여부(1 / 0) - C99
// 6) __STDC_VERSION__: 컴파일러가 사용하는 현재 표준 버전 - C99

#define LOG(message) fprintf(stderr, "[%s(%s):%d] %s\n", __FILE__, __func__, __LINE__, message)

int main(void)
{
    LOG("hello");

    printf("%d\n", __STDC__);

#ifdef __STDC_VERSION__
    printf("%ld\n", __STDC_VERSION__);
#endif
    // 199901L: C99
    // 201112L: C11
    // 201710L: C17

    return 0;
}
