#include <iostream>
using namespace std;
const int MAXN = 15001;
const int MAXLEN = 32001;
int tree[MAXLEN<<2];//¾²Ì¬Ïß¶ÎÊ÷ 
int tx, ty;
int n;
int ans[MAXN];
int ct;
void insert(int id, int st, int ed)
{
    if (st == ed)
        ct += tree[id];
    else
    {
        int mid = (st+ed)>>1;
        if (tx <= mid)
            insert(id<<1,st,mid);
        else
        {
            ct += tree[id<<1];
            insert((id<<1)+1,mid+1,ed);
        }
    }
    ++tree[id];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tx >> ty;
        ct = 0;
        insert(1,0,32000);
        ++ans[ct];
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;
    //system("pause");
    return 0;
}
