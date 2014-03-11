/*
    ID : jake1994
    PROG : window
    LANG : C++
*/
//˼·�������и�
//Note��Ҫע�������ѭ���������ǰ��Լ�������д��Ҫ����ע��
//��������������㣬Ҫʱ��ע���Ƿ������������˼�鸳ֵʱ�Ƿ���������
//����Ҫע��������ʱ�Ƿ���ܲ��������ֵ
//�����Ĵ��������Ǻ��Ѽ�������
//���������Ⱑ��ǧ��֮�̣�������Ѩ 
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
const int MAXN = 300;
template <class T>
inline void ex(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}
struct window
{
    int lx, ly, rx, ry;
    char type;
}win[MAXN];
int size;
int height[MAXN];
int area[MAXN];
double per[MAXN];
void rise(int lx, int ly, int rx, int ry, int hit, int type)
{
//    fout << lx << ' ' << ly << ' ' << rx << ' ' << ry << endl;
    while (hit <= size && (lx>=win[hit].rx||ly>=win[hit].ry||rx<=win[hit].lx||ry<=win[hit].ly))
        hit++;
    if (hit > size)
    {
        per[type] += 100*((rx-lx)*(ry-ly)/double(area[type]));
    }
    else
    {
        if (lx < win[hit].lx)
        {
            rise(lx,ly,win[hit].lx,ry,hit+1,type);
            lx = win[hit].lx;
        }
        if (rx > win[hit].rx)
        {
            rise(win[hit].rx,ly,rx,ry,hit+1,type);
            rx = win[hit].rx;
        }
        if (ly < win[hit].ly)
            rise(lx,ly,rx,win[hit].ly,hit+1,type);
        if (ry > win[hit].ry)
            rise(lx,win[hit].ry,rx,ry,hit+1,type);
    }
}
void totop(int t)
{
    for (int i = height[t]; i < size; i++)
    {
        ex(win[i],win[i+1]);
        height[win[i].type] = i;
    }
    height[t] = size;
}
void tobot(int t)
{
    for (int i = height[t]; i > 1; i--)
    {
        ex(win[i],win[i-1]);
        height[win[i].type] = i;
    }
    height[t] = 1;
}
int main()
{
    fout << fixed << setprecision(3);
    while (1)
    {
        char ch, t;
        fin >> ch;
        if (!fin)
            break;
        switch (ch)
        {
            case 'w':
            {
                size++;
                fin >> t >> t;
                win[size].type = t;
                height[t] = size;
                int lx, ly, rx, ry;
                fin >> t >> lx >> t >> ly >> t >> rx >> t >> ry >> t;
                if (lx > rx)
                    ex(lx,rx);
                if (ly > ry)
                    ex(ly,ry);
                win[size].lx = lx;
                win[size].ly = ly;
                win[size].rx = rx;
                win[size].ry = ry;
                area[win[size].type] = (ry-ly)*(rx-lx);
                break;
            }
            case 't':
            {
                fin >> t >> t;
                totop(t);
                fin >> t;
                break;
            }
            case 'b':
            {
                fin >> t >> t;
                tobot(t);
                fin >> t;
                break;
            }
            case 'd':
            {
                fin >> t >> t;
                totop(t);
                size--;
                fin >> t;
                break;
            }
            case 's':
            {
                fin >> t >> t;
                per[t] = 0;
                int pos = height[t];
                rise(win[pos].lx,win[pos].ly,win[pos].rx,win[pos].ry,pos+1,t);
                fout << per[t] << endl;
                fin >> t;
                break;
            }
        }
    }
    return 0;
}
