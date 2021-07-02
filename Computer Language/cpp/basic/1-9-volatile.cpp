#include <iostream>
using namespace std;

/**
 * 被 volatile 修饰的变量，在对其进行读写操作时，会引发一些可观测的副作用。
 * 而这些可观测的副作用，是由程序之外的因素决定的。
 * 
 * volatile应用
 * 硬件寄存器 的 for 循环，不会被编译器所优化。
 * 这时候就该使用volatile通知编译器这个变量是一个不稳定的，在遇到此变量时候不要优化。
 * 
 * 如果将变量i加上volatile修饰，则编译器保证对变量i的读写操作都不会被优化，
 * 从而保证了变量i被外部程序更改后能及时在原程序中得到感知。
 * 
 * 多线程应用种被多个任务共享的变量
 * 
 * 
 * 
 * volatile 关键字声明的变量，每次访问时都必须从内存中取出值
 * （没有被 volatile 修饰的变量，可能由于编译器的优化，从 CPU 寄存器中取值）
 * 
 * const 可以是 volatile （如只读的状态寄存器）
 * 指针可以是 volatile
 */

int main()
{
    //
    cout << "volatile" << endl;
    return 0;
}
