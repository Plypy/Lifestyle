#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 105;
int ans;
int ar[MAXN];
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    qsort(ar+1, n, sizeof(int), cmp);
    int m = int(double(n)/2+1);
    for (int i = 1; i <= m; i++)
        ans += int(double(ar[i])/2+1);
    cout << ans << endl;
    //system("pause");
    return 0;
}
