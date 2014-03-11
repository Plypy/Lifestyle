/*
  ID: jake1994
  PROG: beads
  LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;
    fin >> n;
    string lace;
    fin >> lace;
    lace += lace;
    int ans = 0;
    int a = 0, b = 0, c = 0;
    char ch = 'b';
    for (int i = 0; i < lace.size() && ans < n; i++)
    {
        if (ch == lace[i])
        {
            a++;
            c = 0;
        }
        else if (lace[i] == 'w')
        {
            a++;
            c++;
        }
        else
        {
            b = a-c;
            ch = lace[i];
            a = c+1;
            c = 0;
        }
        if (ans < a+b)
            ans = a+b;
    }
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
