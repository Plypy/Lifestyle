//定义 f[i][j]表示前i本书，加上第i本共保留了j本书最多能 
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 110;
int n, k;
struct BOOK
{
    int ht;
    int wd;
} book[MAXN];
void load()
{
    cin >> n >> k;
    k = n-k; 
    for (int i = 1; i <= n; ++i)
        cin >> book[i].ht >> book[i].wd;
}
int cmp(const void *a, const void *b)
{
    return ((BOOK *)a)->ht - ((BOOK *)b)->ht;
}
const int INF = 52111425;
int f[MAXN][MAXN]; 
void work()
{
    qsort(book+1,n,sizeof(BOOK),cmp);
    for (int j = 2; j <= k; ++j)
        for (int i = j; i <= n; ++i)
        {
            f[i][j] = INF;
            for (int t = j-1; t < i; ++t)
                f[i][j] = min(f[i][j], f[t][j-1]+abs(book[i].wd-book[t].wd));
        }
    int ans = INF;
    for (int i = k; i <= n; ++i)
        ans = min(ans,f[i][k]);
    cout << ans << endl;
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
}
