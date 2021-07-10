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
    Person *employ;//���ְ����Ϣ������
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
        //����[]����������
        Person *p;
        for(p = employ; p < employ + n; p++)
        {
            //������ڴ���
            if(strcmp(p->name, name) == 0)
                return p->salary;
        }
        //�����ڵ�����Ĵ���
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
    s["����"] = 2188.88;
    s["��˹"] = 1230.07;
    s["����"] = 3200.97;

    cout << "����\t" << s["����"] << endl;
    cout << "��˹\t" << s["��˹"] << endl;
    cout << "����\t" << s["����"] << endl;

    cout << "����Ϊdisplay�����\n\n";
    s.display();
    return 0;
}