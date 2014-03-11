#include <iostream>
#include <math.h>
using namespace std;
const int MAXN = 1001;
int n, m, k;
struct student
{
    int var;
    int avg;
    int idx;
} stu[MAXN];
int cmp(const void*a, const void*b)
{
    if (((student*)a)->avg > ((student*)b)->avg)
        return -1;
    if (((student*)a)->avg == ((student*)b)->avg)
    {
        if (((student*)a)->var < ((student*)b)->var)
            return -1;
        if (((student*)a)->var == ((student*)b)->var)
            if (((student*)a)->idx < ((student*)b)->idx)
                return -1;
    }
    return 1;
}
int main()
{
    cin >> n >> m >> k;
    int tmp;
    int sum, va;
    int tot;
    for (int i = 1; i <= n; i++)
    {
        stu[i].idx = i;
        sum = tot = 0;
        for (int j = 1; j <= k; j++)
        {
            cin >> tmp;
            sum += tmp;
            tot += tmp*tmp;
        }
        stu[i].avg = sum/k;
        stu[i].var = (tot-k*(stu[i].avg)*(stu[i].avg))/k;
    }
    qsort(stu+1,n,sizeof(student),cmp);
    for (int i = 1; i < m; i++)
        cout << stu[i].idx << ' ';
    cout << stu[m].idx;
    return 0;
}
