/*
    ID : jake1994
    PROG : cowxor
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cowxor.in");
ofstream fout("cowxor.out");
const int MAXN = 100001;
int tot[MAXN];
bool trie[1<<22];
int n;
void load()
{
    fin >> n;
    int t;
    for (int i = 1; i <= n; ++i)
    {
        fin >> t;
        tot[i] = tot[i-1]^t;
    }
}
void insert(int x)
{
    int t = 1;
    for (int i = 20; i >= 0; --i)
    {
        t = (t<<1)+((x>>i)&1);
        trie[t] = true;
    }
}
void work()
{
    insert(0);
    int ans = tot[1];
    int ed = 1;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = 0;
        int t = 1;
        int p;
        for (int j = 20; j >= 0; --j)
        {
            p = !((tot[i]>>j)&1);
            if (trie[(t<<1)+p])
            {
                t = (t<<1)+p;
                tmp = (tmp<<1)+p;
            }
            else
            {
                t = (t<<1)+!p;
                tmp = (tmp<<1)+!p;
            }
        }
        if ((tmp^tot[i]) > ans)
        {
            ed = i;
            ans = tmp^tot[i];
        }
        insert(tot[i]);
    }
    int st;
    for (st = ed-1; st; --st)
        if ((tot[st]^tot[ed]) == ans)
            break;
    fout << ans << ' ' << st+1 << ' ' << ed << endl;
}
int main()
{
    load();
    work();
    return 0;
}
