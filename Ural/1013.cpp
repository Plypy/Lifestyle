#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 1801;
const int BAS = 100000000;
const int BNUM = int(log10(double(BAS)));
int n, k;
inline int max(int a, int b)
{
    return a>b?a:b;
}
class hpint
{
private:
    int num[MAXN];
    int size;
public:
    hpint()
    {
        memset(num,0,sizeof(num));
        size = 1;
    }
    int &operator[](const int id)
    {
        return num[id];
    }
    hpint &operator=(const int t)
    {
        num[1] = t;
        size = 1;
        return *this;
    }
    hpint &operator=(const hpint &t)
    {
        memcpy(num,t.num,sizeof(num));
        size = t.size;
        return *this;
    }
    friend ostream &operator<<(ostream &os, hpint &t)
    {
        os << t[t.size];
        int dig;
        for (int i = t.size-1; i; --i)
        {
            if (t[i])
                dig = int(log10(double(t[i]))+1.0);
            else
                dig = 1;
            for (; dig < BNUM; ++dig)
                os << 0;
            os << t[i];
        }
        return os;
    }
    friend hpint operator+(hpint a, hpint b)
    {
        hpint tmp;
        tmp.size = max(a.size,b.size);
        for (int i = 1; i <= tmp.size; ++i)
        {
            tmp[i] += a[i]+b[i];
            if (tmp[i] >= BAS)
            {
                ++tmp[i+1];
                tmp[i] -= BAS;
            }
        }
        if (tmp[tmp.size+1])
            ++tmp.size;
        return tmp;
    }
    friend hpint operator*(hpint a, int t)
    {
        hpint tmp;
        tmp.size = a.size;
        int rest = 0;
        for (int i = 1; i <= tmp.size; ++i)
        {
            tmp[i] = a[i]*t+rest;
            rest = tmp[i]/BAS;
            tmp[i] %= BAS;
        }
        if (rest)
            tmp[++tmp.size] = rest;
        return tmp;
    }
}; 
hpint f[3];
int main()
{
    cin >> n >> k;
    f[0] = 1;
    f[1] = --k;
    for (int i = 2; i <= n; ++i)
        f[i%3] = (f[(i-1)%3]+f[(i-2)%3])*k;
    cout << f[n%3] << endl;
    
    //system("pause");
    return 0;
}
