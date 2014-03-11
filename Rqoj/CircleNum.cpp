#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 101;
const int BAS = 10;
class bignum
{
private:
    int num[MAXN];
    int size;
public:
    bignum()
    {
        memset(num,0,sizeof(num));
        size = 1;
    }
    bignum(bignum &t)
    {
        memcpy(num,t.num,sizeof(num));
        size = t.size;
    }
    bignum(int i)
    {
        memset(num,0,sizeof(num));
        num[1] = i;
        size = 1;
    }
    void clear()
    {
        memset(num,0,sizeof(num));
        size = 1;
    }
    int &operator[](int id)
    {
        return num[id];
    }
    bignum &operator=(bignum &t)
    {
        memcpy(num,t.num,sizeof(num));
        size = t.size;
        return *this;
    }
    bignum &operator*=(bignum &t)
    {
        bignum tmp;
        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= t.size; j++)
                if (i+j-1 < MAXN)
                    tmp[i+j-1] += num[i]*t[j];
        int bound = min(MAXN-1,size+t.size);
        int plus = 0;
        for (int i = 1; i <= bound; i++)
        {
            tmp[i] += plus;
            plus = tmp[i]/BAS;
            tmp[i] %= BAS;
        }
        memcpy(num,tmp.num,sizeof(num));
        if (bound < MAXN && num[bound])
            size = bound;
        else
            size = bound-1;
        return *this;
    }
    bignum &operator+=(bignum &t)
    {
        size = max(size,t.size);
        for (int i = 1; i <= size; i++)
        {
            num[i] += t.num[i];
            if (num[i]>=BAS)
            {
                num[i]-=BAS;
                if (i+1 < MAXN)
                    num[i+1]++;
            }
        }
        if (size+1 < MAXN && num[size+1])
            size++;
        return *this;
    }
    bignum &operator*=(int st)
    {
        int plus = 0;
        for (int i = 1; i <= size; i++)
        {
            num[i] = num[i]*st+plus;
            plus = num[i]/BAS;
            num[i] %= BAS;
        }
        if (size < MAXN-1 && plus)
        {
            num[++size] = plus;
        }
        return *this;
    }
    friend istream &operator>>(istream &is, bignum &t)
    {
        t.clear();
        string tmp;
        is >> tmp;
        t.size = tmp.size();
        for (int i = 0; i < t.size; i++)
            t[t.size-i] = tmp[i]-'0';
        return is;
    }
    friend ostream &operator<<(ostream &os, bignum &t)
    {
        for (int i = t.size; i; i--)
            os << t[i];
        return os;
    }
}n, ans;
int k;

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> k;
    bignum fac(n);
    bignum mem(n);
    bignum ct(1);
    bignum tmp;
    bool fail = false;
    for (int i = 1; i <= k; i++)
    {
        int j;
        //cout << ct << endl;
        if (i != 1 && mem[i] == n[i])
            continue;
        for (j = 1; j <= 10; j++)
        {
            ans += ct;
            //cout << ans << endl;
            n *= fac;
            if (mem[i] == n[i])
                break;
        }
        if (j == 11)
        {
            fail = true;
            break;
        }
        if (i == 1)
            ct *= j;
        else
            ct *= (j+1);
        tmp = fac;
        if (i == 1)
            j--;
        for (int t = 1; t <= j; t++)
            fac *= tmp;
        //cout << i << ' ' << j << ' ' << ans << ' ' << n << endl;
    }
    if (fail)
        cout << -1 << endl;
    else
        cout << ans << endl;
    //system("pause");
    return 0;
}
