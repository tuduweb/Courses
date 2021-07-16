#include <iostream>
#include <cstring>
using namespace std;//新加入
/**
 * 有一销售人员类Sales，其数据成员有姓名name，身份证id，年龄age。
 * 重载输入/输出运算符实现对Sales类数据成员的输入和输出。
 */

class Sales{
    private:
        char name[10];
        char id[18];
        int age;
    public:
        Sales(char *Name, char *ID, int Age);

        friend Sales &operator<<(ostream &os, Sales &s);
        friend Sales &operator>>(istream &is, Sales &s);
        
};

Sales::Sales(char *Name, char *ID, int Age){
    strcpy(name, Name);
    strcpy(id, ID);
    age = Age;
}

Sales& operator<<(ostream &os, Sales &s){
    os << s.name << "\t";
    os << s.id << "\t";
    os << s.age << endl;
    return s;
}

Sales& operator>>(istream &is, Sales &s){
    cout << "输入雇员的姓名，身份证号，年龄" << endl;
    is >> s.name >> s.id >> s.age;
    return s;
}

int main()
{
    Sales s1("杜康", "214131221", 40);
    cout << s1;
    cout << endl;
    cin >> s1;
    cout << s1;
    system("pause");
    return 0;
}