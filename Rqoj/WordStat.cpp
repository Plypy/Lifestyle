#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXK = 45;
const int MAXLEN = 250;
const int MAXS = 10;
string word[MAXS];
int wlen[MAXS];
string pat;
int len;
int p, k, s;
void load()
{
    string tmp;
    cin >> p >> k;
    cin.get();
    pat = ".";
    for (int i = 1; i <= p; ++i)
    {
        getline(cin,tmp);
        pat += tmp;
    }
    len = pat.size()-1;
    cin >> s;
    for (int i = 1; i <= s; ++i)
    {
        cin >> word[i];
        wlen[i] = word[i].size();
    }
}
int f[MAXLEN][MAXK];
int max(int a, int b)
{
    return a>b?a:b;
}
int wdlen[MAXLEN];
void init()
{
    memset(wdlen,0xff,sizeof(wdlen));
    for (int i = 1; i <= len; ++i)
        for (int j = 1; j <= s; ++j)
            if (i+wlen[j]-1 <= len && pat.substr(i,wlen[j]) == word[j])
                if (wdlen[i] == -1 || wdlen[i] > wlen[j])
                    wdlen[i] = wlen[j];
}
int mem[MAXLEN][MAXLEN];
int find(int st, int ed)
{
    if (mem[st][ed])
        return mem[st][ed];
    int ret = 0;
    for (int i = st; i <= ed; ++i)
        if (wdlen[i] != -1 && i+wdlen[i]-1 <= ed)
            ++ret;
    return mem[st][ed] = ret;
}
void work()
{
    init();
    for (int i = 1; i <= len; ++i)
        f[i][1] = find(1,i);
    for (int i = 2; i <= k; ++i)
        for (int j = i; j <= len; ++j)
            for (int t = i-1; t < j; ++t)
                f[j][i] = max(f[j][i],f[t][i-1]+find(t+1,j));
    cout << f[len][k] << endl;
}
int main()
{
    load();
    work();
    return 0;
}
/*
1 3
thisisabookyouareaoh
4
is
a
ok
sab

7 
ั๙ภýหตร๗:
this/isabookyoua/reaoh
*/
