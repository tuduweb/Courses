#include <iostream>
using namespace std;

#if 0
/**
 * 作用域不受限，会引起命名冲突。
 */
enum Color {RED, BLUE};
enum Feeling {EXCITED, BLUE};
#endif


#if 1
/**
 * 经典做法
 * 简单方法：解决作用域不受限带来的命名冲突问题的一个简单方法是，给枚举变量命名时加前缀，如上面例子改成 COLOR_BLUE 以及 FEELING_BLUE。
 */
namespace Color
{
    enum Type
    {
        RED = 15,
        YELLOW,
        BLUE
    };
};
/**
 * 这样之后就可以用 Color::Type c = Color::RED; 来定义新的枚举变量了。
 * 如果 using namespace Color 后，前缀还可以省去，使得代码简化。
 * 不过，因为命名空间是可以随后被扩充内容的，所以它提供的作用域封闭性不高。
 * 在大项目中，还是有可能不同人给不同的东西起同样的枚举类型名。
 */
#endif

#if 1
/**
 * 使用struct
 * 
 * 更“有效”的办法是用一个类或结构体来限定其作用域，
 * 例如：定义新变量的方法和上面命名空间的相同。
 * 不过这样就不用担心类在别处被修改内容。
 * 这里用结构体而非类，
 * 一是因为[本身]希望这些常量可以公开访问，
 * 二是因为它只包含数据没有成员函数。
 */

struct Color1
{
    enum Type
    {
        RED = 102,
        YELLOW,
        BLUE
    };
};
#endif


#if 0
/**
 * C++11的枚举类
 * C++11引入了"enum class"枚举类，可以较好的解决上述问题。
 * 
 * 新的enum的作用域不在是全局的
 * 不能隐式转换成其他类型
 */
/**
 * @brief C++11的枚举类
 * 下面等价于enum class Color2:int
 */
enum class Color2
{
    RED=2,
    YELLOW,
    BLUE
};
/**
 * 可以使用特定类型来存储enum
 */
enum class Color3:char
{
    RED = 'r',
    BLUE
};

int main()
{
    Color2 c2 = Color2::RED;
    cout << static_cast<int>(c2) << endl; //必须转！

    char c3 = static_cast<char>(Color3::BLUE);
    cout << c3 << endl;
    return 0;
}
#endif

/**
 * 类中的枚举类型
 * 
 * 有时我们希望某些常量只在类中有效。
 *  由于#define 定义的宏常量是全局的，
 * 不能达到目的，于是想到实用const 修饰数据成员来实现。
 * 而const 数据成员的确是存在的，但其含义却不是我们所期望的。
 * 
 * const数据成员只在某个对象生存期内是常量，而对于整个类来说是可变的。
 * 因为类可以创建多个对象，不同对象其const数据成员的值可以不同。
 */

#if 0
class A
{
public:
    A(int size);// 声明构造函数
    const int SIZE;
};

A::A(int size) : SIZE(size)//定义构造函数
{
    //
}

int main()
{
    //类内的cosnt值不同
    A a(100);
    A b(200);

    return 0;
}
#endif

#if 0

// class B
// {
//     const int SIZE = 100;
//     int array[SIZE];//error: invalid use of non-static data member 'B::SIZE'
// };

class C
{
    static const int SIZE = 100;
    int array[SIZE];
};


int main()
{
    return 0;
}

#endif

#if 1
/**
 * 怎么样才能建立在整个类中都恒定的变量呢?
 * 
 * 使用类中的枚举变量来实现。
 */

class Person{
public:
    typedef enum {
        BOY = 0,
        GIRL
    }SexType;
};
//访问的时候通过，Person::BOY或者Person::GIRL来访问
#endif


#if 1

class Apple{
public:
    enum Color{
        RED = 10000,
        GREEN
    };
};

int main()
{
    cout << Apple::RED;
    return 0;
}


#endif


