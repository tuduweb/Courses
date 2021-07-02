#include <iostream>
using namespace std;

/**
 * 为了实现虚函数，C ++使用一种称为虚拟表的特殊形式的后期绑定。
 * 该虚拟表是用于解决在动态/后期绑定方式的函数调用函数的查找表。
 * 虚拟表有时会使用其他名称，例如“vtable”，“虚函数表”，“虚方法表”或“调度表”。
 * 
 * 此表中的每个条目只是一个函数指针，指向该类可访问的派生函数。
 * 
 * 其次，编译器还会添加一个隐藏指向基类的指针，
 * 我们称之为vptr。vptr在创建类实例时自动设置，以便指向该类的虚拟表。
 * 
 * 因此，它使每个类对象的分配大一个指针的大小。这也意味着vptr由派生类继承，这很重要。
 */

#if 1

#include <iostream>
#include <stdio.h>
using namespace std;

/**
 * @brief 函数指针
 */
typedef void (*Fun)();

/**
 * @brief 基类
 */
class Base
{
    public:
        Base(){};
        virtual void fun1()
        {
            cout << "Base::fun1()" << endl;
        }
        virtual void fun2()
        {
            cout << "Base::fun2()" << endl;
        }
        virtual void fun3(){}
        ~Base(){};
};

/**
 * @brief 派生类
 */
class Derived: public Base
{
    public:
        Derived(){};
        void fun1()
        {
            cout << "Derived::fun1()" << endl;
        }
        void fun2()
        {
            cout << "DerivedClass::fun2()" << endl;
        }
        ~Derived(){};
};
/**
 * @brief 获取vptr地址与func地址,vptr指向的是一块内存，这块内存存放的是虚函数地址，这块内存就是我们所说的虚表
 *
 * @param obj
 * @param offset
 *
 * @return 
 */
Fun getAddr(void* obj,unsigned int offset)
{
    cout<<"======================="<<endl;
    void* vptr_addr = (void *)*(unsigned long *)obj;  //64位操作系统，占8字节，通过*(unsigned long *)obj取出前8字节，即vptr指针
    printf("vptr_addr:%p\n",vptr_addr);

    /**
     * @brief 通过vptr指针访问virtual table，因为虚表中每个元素(虚函数指针)在64位编译器下是8个字节，因此通过*(unsigned long *)vptr_addr取出前8字节，
     * 后面加上偏移量就是每个函数的地址！
     */
    void* func_addr = (void *)*((unsigned long *)vptr_addr+offset);
    printf("func_addr:%p\n",func_addr);
    return (Fun)func_addr;
}
int main(void)
{
    Base ptr;
    Derived d;
    Base *pt = new Derived(); // 基类指针指向派生类实例
    Base &pp = ptr; // 基类引用指向基类实例
    Base &p = d; // 基类引用指向派生类实例
    cout<<"基类对象直接调用"<<endl;
    ptr.fun1();
    cout<<"基类对象调用基类实例"<<endl;
    pp.fun1(); 
    cout<<"基类指针指向派生类实例并调用虚函数"<<endl;
    pt->fun1();
    cout<<"基类引用指向派生类实例并调用虚函数"<<endl;
    p.fun1();

    // 手动查找vptr 和 vtable
    Fun f1 = getAddr(pt, 0);
    (*f1)();
    Fun f2 = getAddr(pt, 1);
    (*f2)();
    delete pt;
    return 0;
}

#endif