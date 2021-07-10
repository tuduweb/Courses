#include <iostream>
using namespace std;

/**
 * decltype
 * 
 * decltype(expression)
 */


#if 0
/**
 * 推导出表达式的类型
 */
int i = 4;
decltype(i) a;


/**
 * 与using/typedef合用，用于定义类型。
 */
using size_t = decltype(sizeof(0));//sizeof(0)的返回值为size_t类型
using ptrdiff_t = decltype( (int *)0 - (int *)0 );
using nullptr_t = decltype(nullptr);
#include <vector>
vector<int >vec;
typedef decltype(vec.begin()) vectype;

int main()
{
    int ix = 4;
    decltype(ix) a;

    a = 100;

    cout << a;

    for(int i = 0; i < 10; ++i)
        vec.push_back(i);

    for(vectype i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << "\n";
    }

    return 0;
}
#endif

#if 0
/**
 * 重用（重新使用）匿名类型
 */

struct{
    int d;
    double b;
}anon_s;

//借助decltype，重新使用这个匿名的结构体：
decltype(anon_s) as;//定义了一个上面匿名的结构体

/**
 * 【decltype最大用途】泛型编程中结合auto，用于追踪函数的返回值类型
 */

template<typename T>
auto multiply(T x, T y) -> decltype(x*y)
{
    return x*y;
}

int main()
{
    cout << multiply(10.1, 20.2) << endl;
    return 0;
}

#endif


#if 1
int i = 4;
int arr[5] = {0};
int* ptr = arr;
struct S{ double d; } s;
void OverloadFunc(int);
void OverloadFunc(char);//重载的函数
int&& RvalRef();
const bool Func(int);

//规则一：推导为其类型
decltype(arr) var1;//int 标记符表达式
decltype(ptr) var2;//int* 标记符表达式
decltype(s.d) var3;//double 成员访问 表达式
//decltype(OverloadFunc) var4;//重载函数，编译错误。//decltype cannot resolve address of overloaded function

//规则二：将亡值。推导为类型的右值引用。
decltype(RvalRef()) var5 = 1;

//规则三：左值，推导为类型的引用。
decltype((i))var6 = i; //int&
decltype(true? i : i) var7 = i; //int& 条件表达式返回左值。
decltype(++i) var8 = i; //int& ++i返回i的左值
decltype(arr[5]) var9 = i; //int& []操作返回左值
decltype(*ptr) var10 = i; //int& *操作返回左值
decltype("hello") var11 = "hello"; // const char(&)[9] 字符串字面常量为左值，且为const左值。

//规则四：以上都不是，则推导为本类型
decltype(1) var12; //const int
decltype(Func(1)) var13 = true; // const bool
decltype(i++) var14 = i; // int i++返回右值


int main()
{
    cout << "i = " << i << endl;
    cout << "var6 = " << var6 << endl;
    i = 10;//modify i, int& var6 changed, int var14 not changed
    cout << "var6 = " << var6 << endl;
    cout << "var14 = " << var14 << endl;
    return 0;
}

#endif