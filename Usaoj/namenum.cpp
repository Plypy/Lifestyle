/*
ID: jake1994
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <set>
#include <fstream>
using namespace std;
const char tab[10][3] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'J', 'K', 'L'},
    {'M', 'N', 'O'},
    {'P', 'R', 'S'},
    {'T', 'U', 'V'},
    {'W', 'X', 'Y'}
};
ifstream fin("namenum.in");
ifstream tin("dict.txt");
ofstream fout("namenum.out");
set<string> words;
string key;
bool flag;
void dfs(string ck, int ct)
{
    if (ct == key.size())
    {
        if (words.find(ck) != words.end())
        {
            fout << ck << endl;
            flag = true;
        }
        return ;
    }
    for (int i = 0; i < 3; i++)
        dfs(ck+tab[key[ct]-'2'][i],ct+1);
}
int main()
{
    fin >> key;
    string tmp;
    while (tin)
    {
        tin >> tmp;
        words.insert(tmp);
    }
    string ck;
    dfs(ck,0);
    if (!flag)
        fout << "NONE" << endl;
    fin.close();
    fout.close();
    tin.close();
}
