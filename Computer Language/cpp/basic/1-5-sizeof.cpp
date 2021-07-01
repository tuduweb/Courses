#include <iostream>

using namespace std;

/***
 * 首先来个总结，然后下面给出实际例子，实战！
 * 空类的大小为1字节
 * 一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都是不占用类对象的存储空间。
 * 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
 * 普通继承，派生类继承了所有基类的函数与成员，要按照字节对齐来计算大小
 * 虚函数继承，不管是单继承还是多继承，都是继承了基类的vptr。(32位操作系统4字节，64位操作系统 8字节)！
 * 虚继承,继承基类的vptr。
 **/

#if 0
//空类的大小为1字节
class A{};
int main()
{
    cout << sizeof(A) << endl;
    return 0;
}
#endif

#if 0
//静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小。不管这个类产生了多少个实例，还是派生了多少新的类，静态数据成员只有一个实例。静态数据成员，一旦被声明，就已经存在。 
class A
{
    public:
        //一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都是不占用类对象的存储空间。
        char b;
        //对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
        virtual void func() {};
        virtual void func2() {};
        static int c;
        static int d;
        static int f;
};

int main()
{
    cout << sizeof(A) << endl;
    return 0;
}
#endif

#if 0

class B{
    //对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
    virtual void func();
    virtual void func2();
    virtual void func3();
    virtual void func4();
};

int main()
{
    cout << sizeof(B) << endl;
    return 0;
}

#endif

#if 0

class A
{
    public:
        char a;
        int b;
};

class B:A
{
    public:
        short a;
        long b;
};

class C
{
    A a;
    char c;
};

class A1
{
    public:
        virtual void func(){}
};

class C1:public A1
{
    //对于虚单函数继承，派生类也继承了基类的vptr，所以是8字节??什么意思
    virtual void func2(){};
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(A1) << endl;
    cout << sizeof(C1) << endl;//????
    return 0;
}


#endif

#if 1

class A
{
    virtual void func() {}
};

class B
{
    virtual void func2() {}
};

class C : virtual public A, virtual public B
{
    public:
        virtual void func3() {}
};

class D: public A
{
    public:
        virtual void func4() {}
};

/***
 * 一个类中若有虚函数，（不论是自己的虚函数，还是继承而来的），
 * 那么类中就有一个成员变量：虚函数指针，
 * 这个指针指向一个虚函数表，
 * 虚函数表的第一项是类的typeinfo信息，
 * 之后的项为此类的所有虚函数的地址。
 */
int main()
{
    //派生类虚继承多个虚函数，会继承所有虚函数的vptr
    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << endl;
    cout << sizeof(D);
    return 0;
}


#endif