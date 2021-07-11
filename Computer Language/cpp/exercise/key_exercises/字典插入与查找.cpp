#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    map<const char*, const char*> mp;
    map<const char*, const char*>::iterator iter;

    const char key[3][20] = {"img", "system", "ip"};
    const char value[3][20] = {"d:/a.img", "win7", "193.68.6.3"};

    for(int i = 0; i < 2; i++)
    {
        mp.insert(make_pair(key[i], value[i]));
    }

    mp["addr"] = "�й�";

    for(iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }
    char key1[20];
    cout << "�����밴key����:";
    cin.getline(key1, 20);

    //����Ԫ��
    for(iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(strcmp(iter->first, key1) == 0) {
            cout << iter->first << "���ҳ�����!" << "��Ӧ��ֵΪ:" << iter->second << endl;
        }
    }

    //��һ��ɾ����ʽ
    //findֻ�����ڲ������齨������ʽ ���Ҳ�֧��������cin��
    iter = mp.find("addr");
    if(iter != mp.end()) {
        cout << iter->first << "����key���ҳ�����!" << "��Ӧ��valueΪ��" << iter->second << endl;
        cout << "��ʼɾ��Ԫ��!" << endl;
        mp.erase(iter);
    }

    //�ڶ��ַ�ʽɾ��
    //����keyɾ��Ԫ��
    char drop_key[20];
    //����valueɾ��Ԫ��
    char drop_value[20];
    cout << "�����밴keyɾ����";
    cin.getline(drop_key, 20);
    cout << "�����밴valueɾ����";
    cin.getline(drop_value, 20);

    return 0;
}