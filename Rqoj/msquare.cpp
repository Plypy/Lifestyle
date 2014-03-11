/*
    第四题 魔板
    程序msquare.cpp
    使用 test.in  作为输入文件
    使用 test.out 作为输出文件 
*/
/*
    思路：宽搜即可，记录下每个状态的父亲节点，父亲节点到此节点使用的转换方式和深
    度。使用康托展开算出状态的key进行判重。 
*/ 
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int MAXN = 50000;
const int fac[8] = {5040,720,120,24,6,2,1,1};
ifstream fin("test.in");
ofstream fout("test.out");
struct state
{
    int seq[8];
    int fa;
    char op;
    int dep;
} table[MAXN];
bool used[MAXN];
int que[MAXN];
int bg, ed;
int getkey(int pat[8])
{
    bool hash[9] = {0};
    int ret = 1;
    int p;
    for (int i = 0; i < 8; ++i)
    {
        hash[pat[i]] = true;
        p = pat[i]-1;
        for (int j = 1; j < pat[i]; ++j)
            if (hash[j])
                --p;
        ret += p*fac[i];
    }
    return ret;
}
int dest[8];
void load()
{
    for (int i = 0; i < 8; ++i)
        fin >> dest[i];
}
int target;
void operate(int bas[], int ret[], int type)
{
    switch (type)
    {
        case 1:
            for (int i = 0; i < 8; ++i)
                ret[i] = bas[8-i-1];
            break;
        case 2:
            ret[0] = bas[3];
            ret[1] = bas[0];
            ret[2] = bas[1];
            ret[3] = bas[2];
            ret[4] = bas[5];
            ret[5] = bas[6];
            ret[6] = bas[7];
            ret[7] = bas[4];
            break;
        case 3:
            ret[0] = bas[0];
            ret[1] = bas[6];
            ret[2] = bas[1];
            ret[3] = bas[3];
            ret[4] = bas[4];
            ret[5] = bas[2];
            ret[6] = bas[5];
            ret[7] = bas[7];
            break;
    }
}
void work()
{
    target = getkey(dest);
    que[bg] = 1;
    table[1].fa = 0;
    table[1].dep = 0;
    for (int i = 0; i < 8; i++)
        (table[1].seq)[i] = i+1;
    used[1] = true;
    if (target == 1)
        return;
    
    int now;
    int tseq[8];
    int *ptr;
    int key;
    int tdep;
    while (true)
    {
        now = que[bg++];
        tdep = table[now].dep;
        for (int i = 1; i <= 3; ++i)
        {
            ptr = table[now].seq;
            operate(ptr,tseq,i);
            key = getkey(tseq);
            if (!used[key])
            {
                used[key] = true;
                ptr = table[key].seq;
                memcpy(table[key].seq,tseq,sizeof(tseq));
                table[key].fa = now;
                switch (i)
                {
                    case 1:
                        table[key].op = 'A';
                        break;
                    case 2:
                        table[key].op = 'B';
                        break;
                    case 3:
                        table[key].op = 'C';
                        break;
                }
                table[key].dep = tdep+1;
                que[++ed] = key;
                if (key == target)
                {
                    goto outside;
                }
            }
        }
    }
    outside:
        ;
}
void output()
{
    fout << table[target].dep << endl;
    string output;
    int key = target;
    while (table[key].fa)
    {
        output = table[key].op+output;
        key = table[key].fa;
    }
    fout << output << endl;
    fin.close();
    fout.close();
}
int main()
{
    load();
    work();
    output();
    return 0;
}

