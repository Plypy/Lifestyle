#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 10000;
bool check(int num)
{
    if (num <= 1)
        return false;
    int bound = int(sqrt(num));
    for (int i = 2; i < bound; i++)
        if (!(num%i))
            return false;
    return true;
}
int cmp(const void * a, const void * b)
{
    if (*(int*)a < *(int*)b)
        return -1;
    return 1;
}
int list[MAXN];
int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d",list+i);
    qsort(list+1,n,sizeof(int),cmp);
    int a, b, c;
    a = list[k];
    b = list[n-k+1];
    c = b-a;
    if (check(c))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout << c;
    return 0;
}
