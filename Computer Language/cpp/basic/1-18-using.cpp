#include <iostream>
using namespace std;

void func()
{
    cout << "::func" << endl;
}

namespace ns1 {
    void func()
    {
        cout << "ns1::func" << endl;
    }
}

#define isNs1 1
//#define isGlobal 2

namespace ns2 {
#ifdef isNs1
    using ns1::func;    //  ns1中的函数
#elif isGlobal
    using ::func;   //  全局中的函数
#else
    void func()
    {
        cout << "other::func" << endl;
    }
#endif
}

int main()
{
    //这里是为什么在c++中使用cmath而不是math.h头文件
    ns2::func();

    ::func();
    return 0;
}


/**
 * 改变访问性
 * 
 * 类Derived私有继承了Base，对于它来说成员变量n和成员函数size都是私有的，
 * 如果使用了using语句，可以改变他们的可访问性，
 * 如上述例子中，size可以按public的权限访问，n可以按protected的权限访问。 
 */
#if 1

class Base{
public:
    std::size_t size() const { return n; }
protected:
    std::size_t n;
};

class Derived : private Base {
public:
    using Base::size;
protected:
    using Base::n;
};

#endif

/**
 * 函数重载
 */
#if 1
class Base2{
public:
    void f(){ cout << "f()" << endl; }
    void f(int n){ cout << "Base::f(int)" << endl; }
};

class Derived2: private Base2 {
public:
    using Base2::f;
    void f(int n) {
        cout << "Dervied::f(int)" << endl;
    }
};
#endif


/**
 * 取代typedef
 */
#if 0
typedef vector<int > v1;
using v2 = vector<int >;
#endif