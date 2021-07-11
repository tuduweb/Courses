#include <iostream>
using namespace std;

//函数异常可以抛出去由主函数去处理
void func(int x) {
    try{
        if(x == 0)
            throw "异常";
    //如果希望不论拋出哪种类型的异常都能捕获，可以编写如下 catch 块：
    }catch(...){
        cout << "in func" << endl;
        throw 1;
    }
}

int main(int argc, char const *argv[])
{
    try{
        func(0);
    }catch(int n){
        cout << "in main" << endl;
    }

    system("pause");
    return 0;
}