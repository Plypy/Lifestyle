/*
  ID: jake1994
  PROG: milk2
  LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
const int MAXN = 5005;
struct farmer
{
    int bg;
    int ed;
}dat[MAXN];
int cmp(const void *a, const void *b)
{
    return ((farmer *)a)->bg - ((farmer *)b)->bg;
}
int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> dat[i].bg >> dat[i].ed;
    qsort(dat,n,sizeof(farmer),cmp);
    int max1 = 0, max2 = 0;
    int last = dat[0].bg;
    int beg = dat[0].bg;
    for (int i = 0 ; i < n; i++)
    {
        if (dat[i].bg > last)
        {
            beg = dat[i].bg;
            if (max2 < dat[i].bg-last)
                max2 = dat[i].bg-last;
            last = dat[i].ed;
        }
        else
        {
            if (last < dat[i].ed)
                last = dat[i].ed;
            if (max1 < dat[i].ed-beg)
                max1 = dat[i].ed-beg;
        }
    }
    fout << max1 << ' ' << max2 << endl;
    fin.close();
    fout.close();
    return 0;
}
