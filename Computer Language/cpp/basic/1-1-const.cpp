/***
 * 学习笔记 2020/06/27
 * https://light-city.club/sc/basic_content/const/
***/

#include <iostream>
using namespace std;

#if 0
int main()
{
    //定义常量
    const int a = 100;
    
    std::cout << a;
    
    return 0;
}
#endif

/* 防止修改，起保护作用 */
// void f(const int i){
//     i++;//error
// }

/* 节省空间 避免不必要的内存分配 
const定义常量从汇编的角度来看，只是给出了对应的内存地址，
而不是像#define一样给出的是立即数，
所以，const定义的常量在程序运行过程中只有一份拷贝，而#define定义的常量在内存中有若干个拷贝。
*/

/*
小结：可以发现未被const修饰的变量不需要extern显式声明！
而const常量需要显式声明extern，并且需要做初始化！
因为常量在定义后就不能被修改所以定义时必须初始化。*/


#if 0
int main()
{
    const int p = 3;
    //第一个const 修饰int *的类型 第二个是const的ptr
    const int * const ptr = &p;
    const int * ptr2 = &p;
    cout << *ptr << endl;

    int q = 233;
    const int * const ptr3 = &q;
    cout << *ptr3 << endl;

    int k = 10086;
    int * ptr4 = &k;

    *ptr4 -=100;
    cout << *ptr4 << endl;
    ptr4 = &q;
    cout << *ptr4 << endl;

    const int mm = 1233;
    int kk;
    kk = mm;
    kk++;
    cout << kk << endl;

    int nn = 1455;
    int *const qq = &nn;
    nn++;
    cout << nn << endl;

}
#endif

#if false

const int func1();//无意义

const int* func2();//指向的内容不变

int *const func3();//指针本身不可变 指针这个玩意不可以变化


//参数指针所指内容为常数不可变
void StringCopy(char *dst, const char *src);//给*src加上const，如果函数体内的语句试图改动src的内容，编译器将指出错误。

//效率低，因为函数体内将产生A类型
void func(A a);
//提高效率->更改 缺点：引用参数有可能改变参数a，这是我们不期望的。
void func(A &a);
//解决问题->加const修饰符
void func(const A &a);

//以此类推，是否需要将`void func(int x)`改写为`void func(const int &x)`，以便提高效率？
//完全没有必要，因为内部参数数据类型不存在构造、析构的过程，而且复制也非常的块。


//### 类中使用const
//在一个类中，任何不会修改数据成员的函数应该声明为const类型，不慎修改时编译器指出错误。提高程序的健壮性

//对于类中的const成员变量必须通过初始化列表进行初始化，如：
class Apple
{
    public:
        Apple(int i);
        const int apple_number;
};

Apple::Apple(int i) : apple_number(i)
{
    //
}

//const对象只能访问const成员函数
#endif

#if 1

class Banana{
public:
    Banana(int k);
    void constSay() const;
    void say();
    void sayHello();

    static const int number;

    static const int number_Test = -1;//c++11 support this
};

Banana::Banana(int k)
{
    //
}

void Banana::sayHello()
{
    cout << "hello world" << endl;
}

void Banana::constSay() const
{
    //sayHello();//error const -call-> none-const
}

void Banana::say()
{
    sayHello();
}

const int Banana::number = 10;

int main()
{
    Banana b(1);
    b.say();

    cout << Banana::number << endl;

    cout << Banana::number_Test << endl;
    return 0;


}

#endif


