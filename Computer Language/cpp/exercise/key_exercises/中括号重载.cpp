#include <iostream>
#include <cstring>
using namespace std;
struct Person
{
    double salary;
    char *name;
};
class SalaryManage
{
    Person *employ;//存放职工信息的数组
    int max;
    int n;
public:
    SalaryManage(int Max = 0)
    {
        max = Max;
        n = 0;
        employ = new Person[max];
    }
    //
    double &operator[](char *name)
    {
        //重载[]，返回引用
        Person *p;
        for(p = employ; p < employ + n; p++)
        {
            //如果存在处理
            if(strcmp(p->name, name) == 0)
                return p->salary;
        }
        //不存在的情况的处理
        p = employ + n++;
        p->name = new char[strlen(name) + 1];
        strcpy(p->name, name);
        p->salary = 0;
        return p->salary;
    }

    void display()
    {
        for(int i = 0; i < n; ++i)
            cout << employ[i].name << " " << employ[i].salary << endl;
    }
    
    ~SalaryManage()
    {
        delete employ;
    }
};

int main()
{
    SalaryManage s(3);
    s["张三"] = 2188.88;
    s["里斯"] = 1230.07;
    s["王五"] = 3200.97;

    cout << "张三\t" << s["张三"] << endl;
    cout << "里斯\t" << s["里斯"] << endl;
    cout << "王五\t" << s["王五"] << endl;

    cout << "以下为display的输出\n\n";
    s.display();
    return 0;
}