#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
const int MAXN = 501;
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
    hpint(int st)
    {
        memset(num,0,sizeof(num));
        num[size=1] = st;
    }
    int &operator[](int id)
    {
        return num[id];
    }
    void operator*=(int st)
    {
        int plus = 0;
        for (int i = 1; i <= size; i++)
        {
            num[i] = num[i]*st+plus;
            plus = num[i]/10;
            num[i] %= 10;
        }
        if (size+1<MAXN&&plus)
        {
            num[++size] = plus;
        }
    }
    void operator*=(hpint &t)
    {
        hpint tmp;
        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= t.size; j++)
                if (i+j-1<MAXN)
                    tmp[i+j-1] += num[i]*t[j];
        int nsize = min(t.size+size,MAXN-1);
        int plus = 0;
        for (int i = 1; i <= nsize; i++)
        {
            tmp[i] += plus;
            plus = tmp[i]/10;
            tmp[i] %= 10;
        }
        if (!(nsize < MAXN && tmp[nsize]))
            nsize--;
        size = nsize;
        memcpy(num,tmp.num,sizeof(num));
    }
    friend ostream& operator<<(ostream &os, hpint &t)
    {
        for (int i = t.size; i; i--)
            os << t[i];
        return os;
    }
};
int p;
int main()
{
    cin >> p;
    cout << int(log10(2)*p)+1 << endl;
    hpint ans(1);
    hpint t(2);
    if (p&1)
    {
        ans *= t;
        p >>= 1;
    }
    while (p)
    {
        t *= t;
        if (p&1)
            ans *= t;
        p>>=1;
    }
    ans[1] -= 1;
    for (int i = 500; i; i--)
    {
        cout << ans[i];
    }
    //system("pause");
    return 0;
}
