//Note
//���� ֻҪ��˼·д����
//��������Ŀ����˼
//��̾ͱ����˼�
//Keep going�� keep fighting��
//�ٴθп�һ��
//�����ٴ�noip��ʱ��
//�Ҿ��Ǹ�����
//�������밡
//�����ʵ��
//һ�ж���Ϊ���Լ���ŵ��
//Ҫ��סһ��
//�����
//�����
//������ұ���Χ������ǿ��һ��
//���в�����������Ƶ����� 
#include <iostream>
using namespace std;
int s, t, w;
string list;
bool inc(string&);
int main()
{
    cin >> s >> t >> w;
    cin >> list;
    for (int i = 1; i < 5; i++)//��iλ����ĸ�����ܹ�ʹ�������ĸ������Ҳ����˵��iλ����ĸ�����ִ�С 
    {                           //���Ϊt-(w-i+1) 
        if (inc(list))
            cout << list << endl;
    }
    if (inc(list))//�������������..���������������� 
        cout << list;
    return 0;
}
bool inc(string&A)
{
    bool flag = false;
    for (int i = A.size()-1; i >= 0; i--)
    {
        if (list[i]<'a'+t-w+i)
        {
            list[i]++;
            for (int j = i+1; j < A.size(); j++)
                list[j] = list[j-1]+1;
            flag = true;
            break;
        }
    }
    return flag;
}
