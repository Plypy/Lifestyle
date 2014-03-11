/*
   ID : jake1994
   PROG : crypt1
   LANG : C++
*/
// ¼ÌÐøcopy... 
#include <iostream>
#include <stdio.h>
using namespace std;
bool mark[10];
int n, a, b, num[10];
bool check(int m, int k)
{
   if (m / k > 0) return false;
   do
   {
     if (mark[m % 10] != true)
        return false;
     m /= 10;
   } while (m > 0);
   return true;
}
int main(void)
{
    freopen ("crypt1.in", "r", stdin);
    freopen ("crypt1.out", "w", stdout);    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
    {
      scanf ("%d", &num[i]);
      mark[num[i]] = true;
    }
    int tot(0);
    for (int a1 = 1; a1 <= n; a1++)
      for (int a2 = 1; a2 <= n; a2++)
        for (int a3 = 1; a3 <= n; a3++)
          for (int a4 = 1; a4 <= n; a4++)
            for (int a5 = 1; a5 <= n; a5++)    
            {
              bool flag(true);
              a = num[a1] * 100 + num[a2] * 10 + num[a3];
              if (check(a * num[a4], 1000) == false)
                 flag = false;
              if (check(a * num[a5], 1000) == false)
                 flag = false;
              b = num[a4] * 10 + num[a5];
              if (check(a * b, 10000) == false)
                 flag = false;
              if (flag) tot++;
            } 
   printf("%d\n", tot); 
}
