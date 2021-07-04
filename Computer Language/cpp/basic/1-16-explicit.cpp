#include <iostream>
using namespace std;

/**
 * explicit
 * explicit 修饰构造函数时，可以防止隐式转换和复制初始化
 * explicit 修饰转换函数时，可以防止隐式转换，但按语境转换除外
 * 
 * 请使用explicit修饰那些仅有一个参数的构造函数，避免隐式转换的发生。
 */

class sdk
{
public:
    int test = 9;
    sdk(){}
    operator bool() const {
        return test == 10;
    }
};

struct A
{
    operator bool() const { return true; }
};

struct B
{
    explicit operator bool() const { return true; }
};

int main()
{
    sdk ins;
    if(ins)
    {
        std::cout << "Instance is active" << std::endl;
    } else {
        std::cout << "Instance is in-active error!" << std::endl;
    }

    A a1;
    if (a1) cout << "true" << endl; // OK: A::operator bool()
    bool na1 = a1; // OK: copy-initialization selects A::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization

    B b1;     
    if (b1) cout << "true" << endl; // OK: B::operator bool()
    // bool nb1 = b1; // error: copy-initialization does not consider B::operator bool()
    bool nb2 = static_cast<bool>(b1); // OK: static_cast performs direct-initialization

    return 0;
}
