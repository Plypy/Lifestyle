#include <iostream>
#include <cstdlib>
using namespace std;
class Problem
{
private:
    static const int MAXN = 100005;
    static const int MODNUM = 12345;
    int n;
    int ar[MAXN];
    int buffer[MAXN];
public:
    int merge_sort(int Lbound, int Rbound)
    {
        int ret = 0;
        int mid = (Lbound+Rbound)>>1;
        if (Lbound < mid)
            ret += merge_sort(Lbound,mid);
        if (mid+1 < Rbound)
            ret += merge_sort(mid+1,Rbound);
        int i = Lbound, j = mid+1;
        for (int k = Lbound; k <= Rbound; ++k)
        {
            if ((i <= mid) && (j > Rbound || ar[i] >= ar[j]))
            {
                buffer[k] = ar[i++];
                ret += j-mid-1;
            }
            else
                buffer[k] = ar[j++];
        }
        for (i = Lbound; i <= Rbound; ++i)
            ar[i] = buffer[i];
        return ret%MODNUM;
    }
    int run()
    {
        cin >> n;
        int t;
        for (int i = 1; i <= n; ++i)
        {
            cin >> t;
            ar[i] = t-i;
        }
        cout << merge_sort(1,n) << endl;
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
