/*
    ID : jake1994
    PROG : fact4
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    int n;
    fin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
        while (ans%10 == 0)
            ans /= 10;
        ans %= 10000;
    }
    fout << ans%10 << endl;
    fin.close();
    fout.close();
    return 0;
}
