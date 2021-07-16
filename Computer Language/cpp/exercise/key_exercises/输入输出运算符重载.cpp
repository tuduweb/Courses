#include <iostream>
#include <cstring>
using namespace std;//�¼���
/**
 * ��һ������Ա��Sales�������ݳ�Ա������name�����֤id������age��
 * ��������/��������ʵ�ֶ�Sales�����ݳ�Ա������������
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
    cout << "�����Ա�����������֤�ţ�����" << endl;
    is >> s.name >> s.id >> s.age;
    return s;
}

int main()
{
    Sales s1("�ſ�", "214131221", 40);
    cout << s1;
    cout << endl;
    cin >> s1;
    cout << s1;
    system("pause");
    return 0;
}