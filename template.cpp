#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
string fname = ;
const int fnum = 10;
ifstream fin;
ofstream fout;


void init()
{
}
void load()
{
}
void work()
{
}

string modify(string iname, int id)
{
    const int BUFSIZE = 20;
    int buf[BUFSIZE] = {0};
    int bsize = 0;
    if (0 == id)
        return iname+'0';
    while (id)
    {
        buf[++bsize] = id%10;
        id /= 10;
    }
    for (int i = bsize; i; --i)
        iname += char('0'+buf[i]);
    return iname;
}

int main()
{
    for (int i = 0; i <= fnum; ++i)
    {
        string cur_name = modify(fname,i);
        fin.open((cur_name+".in").c_str());
        fout.open((cur_name+".ans").c_str());

        init();
        load();
        work();

        fin.close();
        fout.close();
    }
    return 0;
}
