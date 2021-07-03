#include <iostream>
using namespace std;

/**
 * 相同的函数，在c和c++种，编译后生成的符号不同
 * 这导致c++中使用c语言实现的函数，在编译链接时，辉出错。这时候`extern "c"`就起作用了
 * 
 * c中调用c++
 * 在c++的头文件中 extern "C"{..}
 */


int main()
{
    return 0;
}