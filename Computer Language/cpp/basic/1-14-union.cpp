#include <iostream>
using namespace std;

/**
 * 联合（union）是一种节省空间的特殊的类，
 * 一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。
 * 当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：
 * 默认访问控制符为Public
 * 可以含有构造函数、析构函数
 * 不能含有引用类型的成员
 * 不能继承自其他类，不能作为基类
 * 不能含有虚函数
 * 匿名union在定义所在作用域可直接访问union成员
 * 匿名union不能包含protected成员或者private成员
 * 全局匿名联合必须是static的
 */

int main()
{
    return 0;
}
