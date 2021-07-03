#include <iostream>
using namespace std;

/**
 * 区分：c语言中的struct c++中的struct
 * 
 * 与C对比如下：
 * C++结构体中不仅可以定义数据，还可以定义函数。
 * C++结构体中可以使用访问修饰符，如：public、protected、private 。
 * C++结构体使用可以直接使用不带struct。
 * C++继承
 * 若结构体的名字与函数名相同，可以正常运行且正常的调用！但是定义结构体变量时候只用用带struct的！
 */

//不适用typedef定义结构体别名

struct Student{

};

void Student(){}

int main()
{
    //有同名函数，必须加上struct区分
    struct Student s;
    return 0;
}