#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int HASH_VALUE = 10007;
const int Hash_PLUS = 37;
int Hashtable[HASH_VALUE];
int Hash(int num)
{
    int ret = num%HASH_VALUE;
    while (Hashtable[ret] && Hashtable[ret] != num)
        ret = (ret+Hash_PLUS)%HASH_VALUE;
    Hashtable[ret] = num;
    return ret;
}
int l, n;
int father[HASH_VALUE<<1];
int Rank[HASH_VALUE<<1];
int find(int a)
{
    int fa = a;
    while (father[fa] != fa)
        fa = father[fa];
    int tmp;
    while (a != fa)
    {
        tmp = a;
        a = father[a];
        father[tmp] = fa;
    }
    return fa;
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (Rank[a] > Rank[b])
        father[b] = a;
    else
    {
        if (Rank[a] == Rank[b])
            ++Rank[b];
        father[a] = b;
    }
}
int main()
{
    while (1)
    {
        cin >> l;
        if (-1 == l)
            break;
        for (int i = 0; i < (HASH_VALUE<<1); ++i)
                father[i] = i;
        memset(Rank,0,sizeof(Rank));
        cin >> n;
        int i;
        int bg, ed;
        string parity;
        for (i = 1; i <= n; ++i)
        {
            cin >> bg >> ed >> parity;
            bg = Hash(bg-1);
            ed = Hash(ed);
            if ('e' == parity[0])
            {
                if (find(bg+HASH_VALUE) == find(ed))
                    break;
                Union(bg,ed);
                Union(bg+HASH_VALUE,ed+HASH_VALUE);
            }
            else
            {
                if (find(bg) == find(ed))
                    break;
                Union(bg+HASH_VALUE,ed);
                Union(bg,ed+HASH_VALUE);
            }
        }
        cout << i-1 << endl;
        for (++i; i <= n; ++i)
            cin >> bg >> ed >> parity;
    }
    return 0;
}
