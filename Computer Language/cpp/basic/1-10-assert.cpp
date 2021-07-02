#include <iostream>
using namespace std;

/**
 * assert
 * 断言，是宏，非函数。其作用是如果它的条件返回错误，则终止程序执行。
 */
#define NDEBUG          // 加上这行，则 assert 不可用
#include <assert.h>

int main()
{
    int x = 7;

    x = 9;

    assert(x == 7);

    cout << "hello world" << endl;

    return 0;
}
