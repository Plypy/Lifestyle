// Note:
// 思路是这样滴：
// 从小到大枚举N进制，然后求出在此进制下相应的x与y然后求其的LCS
// (Longest Common Sequence最长公共子序列), 如果等于y的长度那么就可以
// 一直枚举到y进制？但是貌似范围太大了。
// 不过题解说貌似可以...
// 然后还有对于这道题来说使用LCS代价太大了，应该从左到右选取一个y[i]然后
// 再在x中寻找他，找完所有的就可以了。
#include <iostream>
using namespace std;
const int LEN = 30;
int alist[LEN], blist[LEN];
int alen,       blen;
int x, y;
void tran(int pat, int bas, int ar[], int &arsize)
{
    arsize = 0;
    while (pat)
    {
        ar[++arsize] = pat%bas;
        pat /= bas;
    }
}
int main()
{
    cin >> x >> y;
    if (y > x)
    {
        cout << "No solution" << endl;
        return 0;
    }
    for (int bas = 2; bas <= x; ++bas)
    {
        tran(x,bas,alist,alen);
        tran(y,bas,blist,blen);
        int i,j = 1;
        for (i = 1; i <= blen; ++i)
        {
            for (;j <= alen && alist[j] != blist[i]; ++j)
                continue;
            if (j > alen)
                break;
            ++j;
        }
        if (i == blen+1)
        {
            cout << bas << endl;
            return 0;
        }
        
    }
    cout << "No solution" << endl;
    return 0;
} 
