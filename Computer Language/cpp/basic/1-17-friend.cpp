#include <iostream>
using namespace std;

/**
 * 友元函数
 * 在类声明的任何区域中声明，而定义则在类的外部。
 * friend <类型><友元函数名>(<参数表>);
 * 
 * 友元函数只是一个普通函数，并不是该类的类成员函数，
 * 它可以在任何地方调用，友元函数中通过对象名来访问该类的私有或保护成员。
 * 
 * 友元类
 * friend class <友元类名>
 * 类B是类A的友元，那么类B可以直接访问A的私有成员。
 */

class A
{
public:
    A(int _a) : a(_a) {};
    friend int geta(A &ca);////friend
private:
    int a;

    friend class B;
};

int geta(A &ca)
{
    return ca.a;
}

class B
{
public:
    int bgeta(A ca) {
        return ca.a;
    }
};


int main()
{
    A a(3);
    cout << geta(a) << endl;

    B b;
    cout << b.bgeta(a) << endl;

    return 0;
}