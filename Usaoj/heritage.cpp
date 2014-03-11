/*
    ID : jake1994
    PROG : heritage
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 30;
ifstream fin("heritage.in");
ofstream fout("heritage.out");
string a;
string b;
void build(int bg1, int bg2, int len)
{
    for (int i = bg1; i < bg1+len; i++)
    {
        if (a[i] == b[bg2])
        {
            int lsize = i-bg1;
            int rsize = len-lsize-1;
            if (lsize>0)
                build(bg1, bg2+1, lsize);
            if (rsize>0)
                build(i+1, bg2+lsize+1, rsize);
            fout << b[bg2];
            break;
        }
    }
}
int main()
{
    fin >> a >> b;
    build(0, 0, a.size());
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}
