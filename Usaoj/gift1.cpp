/*
  ID: jake1994
  PROG: gift1
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    const int MAXN = 15;
    vector<string> dat(MAXN);
    map<string,int> money;
    int n;
    fin >> n;
    string tmp;
    for (int i = 1; i <= n; i++)
    {
        fin >> tmp;
        dat[i] = tmp;
        money.insert(make_pair(tmp,0));
    }
    int owned;
    int num;    
    for (int i = 1; i <= n; i++)
    {
        fin >> tmp >> owned >> num;
        if (num)
        {
            money[tmp] += owned%num-owned;
            owned /= num;
        }
        for (int j = 1; j <= num; j++)
        {
            fin >> tmp;
            money[tmp] += owned;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        tmp = dat[i];
        fout << tmp << ' ' << money[tmp] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
