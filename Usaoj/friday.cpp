/*
  ID: jake1994
  PROG: friday
  LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[7];
int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int n;
    fin >> n;
    n += 1900;
    int sum = 13;
    for (int i = 1900; i < n; i++)
    {
        if ((i%4 == 0 && i%100) || i%400 == 0)
            mon[2] = 29;
        for (int j = 1; j < 13; j++)
        {
            ans[sum%7]++;
            sum += mon[j];
        }
        mon[2] = 28;
    }
    fout << ans[6] << ' ' << ans[0] << ' '
        << ans[1] << ' ' << ans[2] << ' '
        << ans[3] << ' ' << ans[4] << ' '
        << ans[5] << endl;
    fin.close();
    fout.close();
    return 0;
}
