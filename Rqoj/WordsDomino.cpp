/*
  Name: WordsDomino.cpp
  Author: Ply_py
  Date: 15-01-11 12:22
*/
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 50;
string dat[MAXN];
bool use[MAXN];
int n;
string bg;
int ans;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dat[i];
        dat[i+n] = dat[i];
    }
    cin >> bg;
}
bool check(string &sr, string &ad, int id)
{
    int len1 = sr.size();
    int len2 = ad.size();
    int bound = len1-len2;
    if (bound < 0)
        bound = 0;
    for (int i = len1-1; i >= bound; i--)
    {
        int j, k;
        for (j = i, k = 0; j < len1 && k < len2 && sr[j] == ad[k]; j++, k++)
            continue;
        if (j == len1 && k < len2)
        {
            sr += ad.substr(k, len2-k);
            use[id] = true;
            ans >?= sr.size();
            return true;
        }
    }
    return false;
}
void solve(string &sr)
{
    string cpy = sr;
    for (int i = 1; i <= 2*n; i++)
    {
        if (!use[i] && check(sr, dat[i], i))
        {
            solve(sr);
            sr = cpy;
            use[i] = false;
        }
    }
}
void output()
{
    cout << ans;
}
int main()
{
    input();
    solve(bg);
    output();
    return 0;
}
/*
sample
5
at
touch
cheat
choose
tact
a
*/
