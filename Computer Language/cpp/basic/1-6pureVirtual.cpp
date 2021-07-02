#include <iostream>

using namespace std;

/**
 * c++中的纯虚函数 是我们没有实现的虚函数！我们只需要声明它! 通过声明中赋值0实现
 * 
 * 纯虚函数：没有函数体的虚函数
 * 抽象类：包含纯虚函数的类
 */

#if 0

class A
{
private:
    int a;
public:
    virtual void show() = 0;
};


int main()
{
    //A a1;//error 抽象类不能创建对象
    A* a2;//可以定义抽象类的指针

    //A *a3 = new A();//不能创建对象

    return 0;
}

#endif


#if 1

class Base{
    public:
        Base() { cout << "Constructor: Base" << endl; }
        virtual ~Base() { cout << "Destructor: Base" << endl; }
};

class Derived : public Base {
    public:
        Derived() { cout << "Constructor: Derived" << endl; }
        ~Derived() { cout << "Destructor: Derived" << endl; }
};

class Base2{
    public:
        Base2() { cout << "Constructor: Base2" << endl; }
        ~Base2() { cout << "Destructor: Base2" << endl; }
};

class Apple : public Base2{
    public:
        Apple() { cout << "constructor" << endl; }
        ~Apple() { cout << "destructor" << endl; }
};

int main()
{
    //Base *var = new Derived();
    //delete var;

    Apple a;

    return 0;
}

#endif