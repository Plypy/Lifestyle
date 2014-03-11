/*要能弄清数据结构的意义
 *只有这样才能确保程序运行无误
 *代码维护简易
----------------------------------- 
 *要切忌在重叠可行域中声明同名变量
 *这样可能会导致编译错误
 *编译错误了一切都完了 
 */
#include <iostream>
using namespace std;
int f[201][201], n, ar[201];
long dp(int a, int b);
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        ar[n+i] = ar[i];
    }
    long ans = 0;
    for (int i = 1; i <= n; i++)
        ans >?= dp(i,i+n);
    cout << ans;
    return 0;
}
long dp(int a, int b)
{
    if (f[a][b])
        return f[a][b];
    long res = 0;
    for (int i = a+1; i < b; i++)
        res >?= dp(a,i)+dp(i,b)+ar[i]*ar[a]*ar[b];
    f[a][b] = res;
    return res;
}
