/*
    ID : jake1994
    PROG : buylow
    LANG : C++
*/
//吼吼吼高精类
//友元函数啊 操作符重载啊 吼吼
//此题判重只需考虑不在值相同的状态之前推即可 
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const int BAS = 100000000;
const int MAXN = 5001;
ifstream fin("buylow.in");
ofstream fout("buylow.out");
inline int max(int a, int b)
{
    return a>b?a:b;
}
class hpint
{
private:
    int num[20];
    int dig;
    inline friend ostream & operator<<(ostream &os, hpint &t)
    {
        os << t.num[t.dig-1];
        for (int i = t.dig-2; i >= 0; i--)
        {
            if (t.num[i] < 10000)
                os << 0;
            if (t.num[i] < 1000)
                os << 0;
            if (t.num[i] < 100)
                os << 0;
            if (t.num[i] < 10)
                os << 0;
            os << t.num[i];
        }
        return os;
    }
public:
    hpint()
    {
        memset(num,0,sizeof(num));
        dig = 1;
    }
    inline void refresh()
    {
        memset(num,0,sizeof(num));
        dig = 1;
    }
    inline void operator+=(hpint &t)
    {
        dig = max(t.dig, dig);
        for (int i = 0; i <= dig; i++)
        {
            num[i] += t.num[i];
            if (num[i] >= BAS)
            {
                num[i] -= BAS;
                ++num[i+1];
            }
        }
        if (num[dig])
            dig++;
    }
    inline void operator++()
    {
        ++num[0];
    }
} ct[MAXN], sum;
int len[MAXN];
int dat[MAXN];
int n;
int ans;
int main()
{
    fin >> n;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        fin >> dat[i];
        tmp = 0;
        for (int j = i-1; j; j--)
            if (dat[j] == dat[i])
            {
                tmp = j;
                break;
            }
        len[i] = 1;
        for (int j = tmp+1; j < i; j++)
        {
            if (dat[j] > dat[i])
            {
                if (len[j]+1 > len[i])
                {
                    len[i] = len[j]+1;
                    ct[i].refresh();
                    ct[i] += ct[j];
                }
                else if (len[j]+1 == len[i])
                {
                    ct[i] += ct[j];
                }
            }
        }
        if (len[i] == 1 && !tmp)
            ++ct[i];
        if (ans < len[i])
            ans = len[i];
    }
    for (int i = ans; i <= n; i++)
        if (len[i] == ans)
            sum += ct[i];
    fout << ans << ' ' << sum << endl;
    fin.close();
    fout.close();
    return 0;
}
