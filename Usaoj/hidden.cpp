/*
  ID: jake1994
  PROG: hidden
  LANG: C++
*/


#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("hidden.in");
ofstream fout("hidden.out");
const int MAXLEN = 10010;
int n;
string str;
string tmp;
void load()
{
    fin >> n;
    while (fin >> tmp)
        str += tmp;
    str += str;
}
void work()
{
    int i = 0, j = 1;
    int k;
    while (j < n)
    {
        for (k = 0; str[i+k] == str[j+k] && k < n; ++k)
            continue;
        if (str[i+k] > str[j+k])
            i = j;
        else
            j += k+1;
        if (j == i)
            ++j;
    }
    fout << i << endl;
}
int main()
{
    load();
    work();
    return 0;
}
