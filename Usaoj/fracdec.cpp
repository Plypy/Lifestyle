/*
    ID : jake1994
    PROG : fracdec
    LANG : C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
const int MAXN = 100005;
bool used[MAXN];
int pos[MAXN];
int out[MAXN];
int main()
{
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    int n, d;
    fin >> n >> d;
    if (n%d == 0)
        fout << n/d << ".0" << endl;
    else
    {
        string ans;
        ostringstream sout;
        int intpart = n/d;
        int remain =  n%d;
        int dig;
        for (int i = 1;;i++)
        {
            if (used[remain])
            {
                sout << intpart << '.';
                for (int j = 1; j < pos[remain]; j++)
                    sout << out[j];
                sout << '(';
                for (int j = pos[remain]; j < i; j++)
                    sout << out[j];
                sout << ')';
                break;
            }
            used[remain] = true;
            pos[remain] = i;
            remain *= 10;
            dig = remain/d;
            out[i] = dig;
            remain %= d;
            if (remain == 0)
            {
                sout << intpart << '.';
                for (int j = 1; j <= i; j++)
                    sout << out[j];
                break;
            }
        }
        ans = sout.str();
        for (int i = 0; i < ans.size(); i++)
        {
            fout << ans[i];
            if (i%76 == 75)
                fout << endl;
        }
        if (ans.size()%76)
            fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
