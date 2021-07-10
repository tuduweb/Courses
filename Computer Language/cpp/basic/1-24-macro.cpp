#include <iostream>
using namespace std;

/**
 * 宏中包含特殊符号
 * 分为几种：#，##，\
 */

#if 0
/**
 * 字符串化操作符 #
 * 在一个宏中的参数前面使用一个#,预处理器会把这个参数转换为一个字符数组，
 * 换言之就是：#是“字符串化”的意思，
 * 出现在宏定义中的#是把跟在后面的参数转换成一个字符串。
 */

#define exp(s) printf("test s is:%s\n", s)
#define exp1(s) printf("test s is:%s\n", #s)
#define exp2(s) #s

int main()
{
    exp("hello");
    exp1("hello world");
    exp1(hello world);
    // test s is:hello
    // test s is:"hello world"
    // test s is:hello world

    string str = exp2( bac );
    cout << str << " " << str.size() << endl;

    string str1 = exp2(asd d sf  s);
    /**
     * 当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
     * 用每个子字符串之间以一个空格连接，忽略剩余空格。
     */
    cout << str1 << " " << str1.size() << endl;
    
    return 0;
}
#endif

#if 0
/**
 * 符号连接操作符 ##
 * 
 * "##"是一种分隔连接方式，它的作用是先分隔，然后进行强制连接。
 * 将宏定义的多个形参转换成一个实际参数名。
 * 
 * 注意事项：
 * 1. 当用##连接形参时，##前后的空格可有可无。
 * 2. 连接后的实际参数名，必须为实际存在的参数名 或 编译器已知的宏定义。
 * 3. 如果##后的参数本身也是一个宏的话，##会阻止这个宏的展开。
 */
#define expA(s) printf("%s\n", gc_##s) //gc_[s]必须存在
#define expB(s) printf("%s\n", gc_ ## s) //gc_[s]必须存在
#define gc_hello1 "I am gc_hello1"

int main()
{
    const char* gc_hello = "i am gc_hello";
    expA(hello);
    expB(hello1);
    return 0;
}
#endif

#if 0
/**
 * 续行操作符 \
 * 当定义的宏不能用一行表达完整时，可以用"\"表示下一行继续此宏的定义。
 * 注意\前留空格。
 */
#define MAX(a, b) ( (a) > (b)? (a) \
                    :(b))


/**
 * do{...}while(0)的使用
 * 避免语义曲解
 */
#if 0
#define fun() f1();f2();
if(a > 0)
    fun()
//宏被展开以后就是
if(a > 0)
    f1();
    f2();
//与本意不相符。为了解决这种问题，在写代码时，通常可以使用{}代码块。如
#define fun1() {f1(); f2();}
if(a > 0)
    fun1();
//宏展开
if(a > 0)
{
    f1();
    f2();
};
//但是会发现上述宏展开后多了一个分号，实际语法不太对。(虽然编译运行没问题，正常没分号)。
#endif
int main()
{
    int max_val = MAX(3, 6);
    cout << max_val << endl;
    return 0;
}

#endif

#if 1
/**
 * 避免使用goto控制流
 * 
 * 在一些函数中，我们可能需要在return语句之前做一些清理工作，
 * 比如释放在函数开始处由malloc申请的内存空间，使用goto语句的一种简单的方法：
 */

int f() {
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    cout << *p << endl;
#ifndef DEBUG
    int error = 1;
#endif
    if(error)
        goto END;
    //do something
END:
    cout << "free" << endl;
    free(p);
    return 0;
}

/**
 * 但由于goto不符合软件工程的结构化，而且有可能使得代码难懂，所以很多人都不倡导使用，
 * 这个时候我们可以使用do{...}while(0)来做同样的事情：
 */
int ff() {
    int *p = (int *)malloc(sizeof(int));
    *p = 10; 
    cout<<*p<<endl;
    do{ 
#ifndef DEBUG
        int error=1;
#endif
        if(error)
            break;
        //dosomething
    }while(0);
    cout<< "free" <<endl;
    free(p);
    return 0;
}
/**
 * 将函数主体部分使用do{..}while(0)包含起来，使用break来代替goto，后续的清理工作在while之后，
 * 现在既能达到同样的效果，而且代码的可读性、可维护性比上面的goto的代码要好很多。
 */



/**
 * 避免由宏引起的警告
 * 内核中由于不同架构的限制，很多时候会用到空宏。在编译的时候，这些空宏会给出warning
 * 为了避免这些warning，我们可以使用do{...}while(0)来定义空宏
 */
#define EMPTYMIRCO do{}while(0)

int main()
{
    return 0;
}


#endif