/*
    ID : jake1994
    PROG : barn1
    LANG : C++
*/
// COPY的程序...这个使用了随机化快排的
// 我是想这道题太简单了...理解思路就好了 
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
ifstream fin ("barn1.in");
ofstream fout ("barn1.out");
int m, s, c;
int a[300], b[300], mark[300];
int qsort(int l, int r)
{
    int i, j, k;
    i = l; j = r; k = a[rand() % (r - l + 1) + l];
    do
    {
      while (i <= j && a[i] < k) i++;
      while (i <= j && a[j] > k) j--;
      if (i <= j)
      {
         a[0] = a[i]; a[i] = a[j]; a[j] = a[0];
         i++; j--;
      }
    } while (i <= j);
    if (l < j) qsort(l, j);
    if (i < r) qsort(i, r);
}
int main(void)
{
    fin >> m >> s >> c;
    for (int i = 1; i <= c; i++)
      fin >> a[i];
    srand (time (0));
    if (c >= 1) qsort(1, c);
    int now(a[c] - a[1] + 1);
    for (int i = 2; i <= c; i++)
      b[i - 1] = a[i] - a[i - 1] - 1;
    for (int i = 1; i < m; i++)
    {
       int max(0), tt(0);       
       for (int j = 1; j < c; j++)
         if (b[j] > max && mark[j] == false)
         {
            tt = j;
            max = b[j];
         }
       mark[tt] = true;
       now -= max;
    }      
    fout << now << endl;
}
