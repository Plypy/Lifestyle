#include <iostream>
#include <limits.h>
using namespace std;
const int MAXM = 101;
const int MAXN = 10001;
int water[MAXM];
int data[MAXN];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int maxi = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", data+i);
    for (int i = 1; i <= m; i++)
    {
        water[i] = data[i];
        maxi >?= water[i];
    }
    water[0] = INT_MAX;
    for (int i = m+1; i <= n; i++)
    {
        int mini = 0;
        for (int j = 1; j <= m; j++)
            if (water[j] < water[mini])
                mini = j;
        water[mini] += data[i];
        maxi >?= water[mini];
    }
    printf("%d", maxi);
    return 0;
}
