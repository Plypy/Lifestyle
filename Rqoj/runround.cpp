/*
ID: jake1994
PROG: runround
LANG: C++
*/
//���� �����ܲ��ܹ�- - 
//��...����stdio.h
//����
//������...
//���� 
//�ð�...ɵ����
//Ӧ�������ݸ��µ�ʱ���������...
//�㷨����ûɶ��.. 
//����Ӧ���ǵ�check����false��ʱ��û��������β����... 
//�������Ī�������...
//��û�㶮 
//���������ĥ��...
//���ڵ�һ�ι���99...
//�ҾͲ���ȫ�ֱ�������
//����һ�� 
//����������
//Ҳ��֪��һ��ʼΪɶ��... 
#include <iostream>
#include <stdio.h> 
#include <string.h>
using namespace std;
bool check(int num);
int ha[10];
bool list[10];
int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    int n;
    cin >> n;
    while (!check(++n))
        continue;
    cout << n << endl;
    return 0;
}
bool check(int num)
{
    memset(list,0,sizeof(list));
    memset(ha,0,sizeof(ha));
    int a = num, b;
    int p = -1, n;
    while (num)
    {
        num/=10;
        p++;
    }
    n = p+1;
    while (a)
    {
        b = a%10;
        a = a/10;
        if (list[b]||!b)
            return false;
        list[b]=true;
        ha[p--]=b;
    }
    memset(list,0,sizeof(list));
    int ct = n;
    int bg = 0;
    while (1)
    {
        if (ct==0)
        {
            if (bg==0)
                return true;
            else
                return false;
        }
        else
        {
            if (!list[bg])
            {
                ct--;
                list[bg]=true;
            }
            else
                return false;
            bg = (bg+ha[bg])%n;
        }
    }
}
