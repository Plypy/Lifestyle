// 用滚动数组的话得注意以前的数据会不会影响现在的
// 也就是说假如要用+=这类操作得先把原来的数据刷掉才可以 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXS = 510;
int n, s;
const int MAXDIGIT = 100;
const int BAS = 10000;
const int BASDIGIT = int(log10(double(BAS)));
inline int max(int a, int b)
{
    return a>b?a:b;
}
class hpint
{
private:
    int num[MAXDIGIT];
public:
    hpint(int st = 0, int _size = 1)
    {
        memset(num,0,sizeof(num));
        num[1] = st;
        num[0] = _size;
    }
    int &operator[](int x)
    {
        return num[x];
    }
    hpint &operator=(int st)
    {
        memset(num,0,sizeof(num));
        num[1] = st;
        num[0] = 1;
        return *this;
    }
    hpint &operator+=(hpint &t)
    {
        int tsize = max(t[0],num[0]);
        for (int i = 1; i <= tsize; ++i)
        {
            num[i] += t[i];
            if (num[i] >= BAS)
            {
                num[i] -= BAS;
                ++num[i+1];
            }
        }
        num[0] = tsize;
        if (num[tsize+1])
            ++num[0];
        return *this;
    }
    hpint &operator*=(hpint &t)
    {
        hpint tmp;
        tmp[0] = num[0]+t[0]-1;
        for (int i = 1; i <= num[0]; ++i)
            for (int j = 1; j <= t[0]; ++j)
                tmp[i+j-1] += num[i]*t[j];
        for (int i = 1; i <= tmp[0]; ++i)
        {
            tmp[i+1] += tmp[i]/BAS;
            tmp[i] %= BAS;
        }
        if (tmp[tmp[0]+1])
            ++tmp[0];
        memcpy(num,tmp.num,sizeof(num));
        return *this;
    }
    friend ostream &operator<<(ostream &os, hpint &t)
    {
        os << t[t[0]];
        int tdig;
        for (int i = t[0]-1; i; --i)
        {
            if (t[i])
                tdig = int(log10(double(t[i])))+1;
            else
                tdig = 1;
            for (int j = tdig+1; j <= BASDIGIT; ++j)
                os << 0;
            os << t[i];
        }
        return os;
    }
};
void load()
{
    cin >> n >> s;
}
hpint f[2][MAXS];
void work()
{
    if (s&1)
        cout << 0 << endl;
    else
    {
        s >>= 1;
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int u = i&1;
            int v = (i-1)&1;
            for (int j = 0; j <= s; ++j)
                f[u][j] = 0;
            for (int j = 0; j <= 9; ++j)
                for (int k = j; k <= s; ++k)
                {
                    f[u][k] += f[v][k-j];
                }
        }
        f[n&1][s] *= f[n&1][s];
        cout << f[n&1][s] << endl;
    }
}
int main()
{
    load();
    work();
    //system("pause");
    return 0;
}
