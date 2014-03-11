// 纱布哦，其实自己已经推出来了，但就是没勇气写... 
// 总的来说，写代码的速度还是太慢 
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 600;
const int BAS = 100000000;
const int BNUM = int(log10(BAS));
const int DIG = 40;
class hpint
{
private:
    int list[DIG];
    int size;
public:
    hpint()
    {
        memset(list,0,sizeof(list));
        size = 1;
    }
    void clear()
    {
        memset(list,0,sizeof(list));
        size = 1;
    }
    hpint &operator++()
    {
        list[1]++;
        return *this;
    }
    hpint &operator=(hpint &t)
    {
        memcpy(list,t.list,sizeof(list));
        size = t.size;
        return *this;
    }
    hpint &operator+=(hpint &t)
    {
        for (int i = 1; i <= t.size; i++)
        {
            list[i] += t.list[i];
            if (list[i] >= BAS)
            {
                list[i] -= BAS;
                list[i+1]++;
            }
        }
        if (t.size > size)
            size = t.size;
        if (list[size+1])
            size++;
        return *this;
    }
    int operator[](int id)
    {
        return list[id];
    }
    friend ostream &operator<<(ostream &os, hpint &t)
    {
        os << t[t.size];
        for (int i = t.size-1; i; i--)
        {
            int e = int(log10(t[i]))+1;
            for (int j = e+1; j<=BNUM; j++)
                os << 0;
            os << t[i];
        }
        return os;
    }
} f[MAXN],g[MAXN], ans; 
int k, w;
int main()
{
    cin >> k >> w;
    int last = (1<<(w%k))-1;
    int num = (1<<k)-1;
    for (int i = 1; i <= num; i++)
        ++g[i];
    int size = w/k+1;
    int p, q;
    for (int i = 2; i <= size; i++)
    {
        for (int j = 0; j <= num; j++)
            f[j].clear();
        for (int j = num; j >= 0; j--)
        {
            f[j] = f[j+1];
            f[j] +=g[j+1];
        }
        if (i!=2)
            ans += f[0];
        for (int j = 0; j <= num; j++)
            g[j] = f[j];
    }
    for (int i = 1; i <= last; i++)
        ans += f[i];
    cout << ans << endl;
//    system("pause");
    return 0;
}
