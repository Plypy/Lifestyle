//递推啊递推 
/*
    ID : jake1994
    PROG : vans
    LANG : C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream fin("vans.in");
ofstream fout("vans.out");
const int MAXSIZE = 1000;
const int BAS = 100000000;
const int BNUM = 8;
inline int max(int a, int b)
{
    return a>b?a:b;
}
class hpint
{
private:
    int num[MAXSIZE];
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
    friend hpint operator-(hpint a, hpint b)
    {
        hpint tmp;
        tmp.size = max(a.size,b.size);
        for (int i = 1; i <= tmp.size; ++i)
        {
            tmp[i] += a[i]-b[i];
            if (tmp[i] < 0)
            {
                tmp[i] += BAS;
                --tmp[i+1];
            }
        }
        for (;tmp[tmp.size]==0 && tmp.size; --tmp.size)
            continue;
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
    friend hpint operator*(int t, hpint a)
    {
        return a*t;
    }
};
hpint f[5];
int main()//超级精简的主体部分 
{
    int n;
    fin >> n;
    f[0] = 0;
    f[1] = 2;
    f[2] = 4;
    f[3] = 12;
    for (int i = 4; i < n; ++i)
        f[i%5] = 2*f[(i-1)%5]+2*f[(i-2)%5]-2*f[(i-3)%5]+f[(i-4)%5];
    fout << f[(n-1)%5] << endl;
    return 0;
}
