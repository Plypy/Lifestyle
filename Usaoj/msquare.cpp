/*
    ID : jake1994
    PROG : msquare
    LANG : C++
*/
/*
    思路：宽搜即可，记录下每个状态的父亲节点，父亲节点到此节点使用的转换方式和深
    度。使用康托展开算出状态的key即可。 
*/ 
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 50000;
const int fac[8] = {5040,720,120,24,6,2,1,1};
ifstream fin("msquare.in");
ofstream fout("msquare.out");
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
    for (int i = 0; i < 8; i++)
    {
        hash[pat[i]] = true;
        p = pat[i]-1;
        for (int j = 1; j < pat[i]; j++)
            if (hash[j])
                p--;
        ret += p*fac[i];
    }
    return ret;
}
int main()
{
    int dest[8];
    for (int i = 0; i < 8; i++)
        fin >> dest[i];
    int target = getkey(dest);
    if (target == 1)
    {
        fout << 0 << endl;
        fout << endl;
        return 0;
    }
    que[bg] = 1;
    table[1].fa = 0;
    table[1].dep = 0;
    for (int i = 0; i < 8; i++)
        (table[1].seq)[i] = i+1;
    used[1] = true;
    
    int now;
    int tseq[8];
    int *ptr;
    int key;
    int tdep;
    while (true)
    {
        now = que[bg++];
        ptr = table[now].seq;
        tdep = table[now].dep;
        // case A
        for (int i = 0; i < 8; i++)
            tseq[i] = ptr[8-i-1];
        key = getkey(tseq);
        if (!used[key])
        {
            used[key] = true;
            ptr = table[key].seq;
            for (int i = 0; i < 8; i++)
                ptr[i] = tseq[i];
            table[key].fa = now;
            table[key].op = 'A';
            table[key].dep = tdep+1;
            que[++ed] = key;
            if (key == target)
                break;
        }
        // case B
        ptr = table[now].seq;
        tseq[0] = ptr[3];
        tseq[1] = ptr[0];
        tseq[2] = ptr[1];
        tseq[3] = ptr[2];
        tseq[4] = ptr[5];
        tseq[5] = ptr[6];
        tseq[6] = ptr[7];
        tseq[7] = ptr[4];
        key = getkey(tseq);
        if (!used[key])
        {
            used[key] = true;
            ptr = table[key].seq;
            for (int i = 0; i < 8; i++)
                ptr[i] = tseq[i];
            table[key].fa = now;
            table[key].op = 'B';
            table[key].dep = tdep+1;
            que[++ed] = key;
            if (key == target)
                break;
        }
        // case C
        ptr = table[now].seq;
        tseq[0] = ptr[0];
        tseq[1] = ptr[6];
        tseq[2] = ptr[1];
        tseq[3] = ptr[3];
        tseq[4] = ptr[4];
        tseq[5] = ptr[2];
        tseq[6] = ptr[5];
        tseq[7] = ptr[7];
        key = getkey(tseq);
        if (!used[key])
        {
            used[key] = true;
            ptr = table[key].seq;
            for (int i = 0; i < 8; i++)
                ptr[i] = tseq[i];
            table[key].fa = now;
            table[key].op = 'C';
            table[key].dep = tdep+1;
            que[++ed] = key;
            if (key == target)
                break;
        }
    }
    fout << table[target].dep << endl;
    string output;
    while (table[key].fa)
    {
        output = table[key].op+output;
        key = table[key].fa;
    }
    fout << output << endl;
    fin.close();
    fout.close();
    return 0;
}
