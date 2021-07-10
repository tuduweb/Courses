#include <iostream>
using namespace std;

/**
 * 引用与指针
 * https://light-city.club/sc/basic_content/pointer_refer/
 * 
 * 引用         指针
 * 必须初始化   可以不初始化
 * 不能为空     可以为空
 * 不能更换目标 可以更换目标
 */

#if 0
//int &r;//不合法，没有 初始化引用
int *p1;
/**
 * 由于引用不能为空，所以我们在使用引用的时候不需要测试其合法性，
 * 在使用指针的时候需要首先判断是否为空指针，否则可能会引起程序崩溃。
 */
void test_p(int* p)
{
    if(p != nullptr)
    {
        *p = 3;
    }
    return;
}

void test_r(int& r)
{
    r = 3;//引用不能为空，所以无需判断
    return;
}


/**
 * 指针可以随时改变指向，但是引用只能指向初始化时指向的对象，无法改变。
 */

int a = 1;
int b = 2;

int &r = a;
int *p = &a;


template<typename T>
void f(T&& t){}


class A
{
public:
    A():m_ptr(new int(0)){cout << "construct" << endl;}
    A(const A& a):m_ptr(new int(*a.m_ptr)) //深拷贝的拷贝构造函数
    {
        cout << "copy construct" << endl;
    }
    ~A(){ delete m_ptr;}
private:
    int* m_ptr;
};
A GetA()
{
    return A();
}
int main()
{
    p = &b;//指针指向了变量b。
    r = b;//引用r仍然指向a，但是a的值变成了b。

    int&& var1 = 1;

    cout << "hello pointer&refer" << endl;
    
    
    f(10);
    int x = 10;
    f(x);
    
    A a = GetA();//无法复现copy_construct


    ///////////////////////////////////
    int foo(42);
    int&& test = foo--;//OK: 后置自减运算符返回的是右值，将它绑定在右值引用上
    //int& test1 = foo++;// Err: 后置自增运算符返回的是右值，不能将它绑定在左值引用上
    int&& quux = foo * 1;//正确
    int& kkk = foo;//正确
    int&& kkke = foo;//错误 foo 可以是左值，所以不能将它绑定在右值引用上

    return 0;
}
#endif

#if 0

#include <iostream>
#include <string>

class Container {
 private:
  typedef std::string Resource;

 public:
  Container() {
    resource_ = new Resource;
    std::cout << "default constructor." << std::endl;
  }
  explicit Container(const Resource& resource) {
    resource_ = new Resource(resource);
    std::cout << "explicit constructor." << std::endl;
  }
  ~Container() {
    delete resource_;
    std::cout << "destructor" << std::endl;
  }
  Container(const Container& rhs) {
    resource_ = new Resource(*(rhs.resource_));
    std::cout << "copy constructor." << std::endl;
  }
  Container& operator=(const Container& rhs) {
    delete resource_;
    resource_ = new Resource(*(rhs.resource_));
    std::cout << "copy assignment." << std::endl;
    return *this;
  }
  Container(Container&& rhs) : resource_(rhs.resource_) {
    rhs.resource_ = nullptr;
    std::cout << "move constructor." << std::endl;
  }
//当右操作数是右值引用时，调用这个版本的赋值运算符。
  Container& operator=(Container&& rhs) {
    Resource* tmp = resource_; resource_ = rhs.resource_; rhs.resource_ = tmp;
    std::cout << "move assignment." << std::endl;
    return *this;
  }

 private:
  Resource* resource_ = nullptr;
};

Container get() {
  Container ret("tag");
  return ret;
}

int main()
{
    Container foo;
    foo = get();
    return 0;
}
// default constructor.
// explicit constructor.
// move assignment.
// destructor
// destructor
//这相当于我们将临时对象 rhs 中的资源「移动」到了 foo 当中，避免了销毁资源再拷贝赋值的开销。

#endif

/**
 * A&&右值引用 可以续临时变量的命，使其不临时
 */







#if 1
/**
 * 完美转发
 * https://liam.page/2016/12/11/rvalue-reference-in-Cpp/
 */
template <typename T, typename ArgT>
std::shared_ptr<T> factory(const ArgT& arg) {
    return shared_ptr<T>(new T(arg));
}

int main()
{
    return 0;
}
#endif

#if 0

//所以，任何一个类型为 右值引用 的变量，一旦初始化完成，性质上就变成和一个 左值引用 毫无差别。这样的语意，对于程序员的使用是最为合理的。
// Foo   foo{10};
// Foo&& ref = foo; // 不合法，右值引用只能由右值初始化

// Foo&& ref1 = Foo{10};
// Foo&& ref2 = ref1; // 不合法，ref1是个左值

#endif

