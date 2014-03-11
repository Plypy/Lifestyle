#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXS = 370000;
int goal[9] = {1,2,3,8,0,4,7,6,5};
int gval;
int fac[9] = {40320,5040,720,120,24,6,2,1};
bool used[MAXS];
struct state
{
    int num[9];
    int pos;
    int step;
}que[MAXS];
int st, ed;
int cantor(int *t)
{
    int ret = 1;
    bool app[10] = {false};
    for (int i = 0; i < 8; i++)
    {
        int ct = 0;
        for (int j = 0; j < t[i] && ct < i; j++)
            if (app[j])
                ct++;
        ret += (t[i]-ct)*fac[i];
        app[t[i]] = true;
    }
    return ret;
}
void load()
{
    char ch;
    for (int i = 0; i < 9; i++)
    {
        cin >> ch;
        if (ch == '0')
            que[st].pos = i;
        que[st].num[i] = ch-'0';
    }
    gval = cantor(goal);
    int tmp;
    used[tmp = cantor(que[st].num)] = true;
    if (tmp == gval)
    {
        cout << 0 << endl;
        exit(0);
    }
}
void work()
{
    int temp[9], tstep, tpos, dpos;
    int tcan;
    while (st <= ed)
    {
        memcpy(temp,que[st].num,sizeof(temp));
        tstep = que[st].step;
        tpos = que[st++].pos;
        if (tpos > 2)
        {
            dpos = tpos-3;
            swap(temp[dpos],temp[tpos]);
            tcan = cantor(temp);
            if (!used[tcan])
            {
                used[tcan] = true;
                memcpy(que[++ed].num,temp,sizeof(temp));
                que[ed].pos = dpos;
                que[ed].step = tstep+1;
            }
            swap(temp[dpos],temp[tpos]);
        }
        if (tpos < 6)
        {
            dpos = tpos+3;
            swap(temp[dpos],temp[tpos]);
            tcan = cantor(temp);
            if (!used[tcan])
            {
                used[tcan] = true;
                memcpy(que[++ed].num,temp,sizeof(temp));
                que[ed].pos = dpos;
                que[ed].step = tstep+1;
            }
            swap(temp[dpos],temp[tpos]);
        }
        if (tpos%3)
        {
            dpos = tpos-1;
            swap(temp[dpos],temp[tpos]);
            tcan = cantor(temp);
            if (!used[tcan])
            {
                used[tcan] = true;
                memcpy(que[++ed].num,temp,sizeof(temp));
                que[ed].pos = dpos;
                que[ed].step = tstep+1;
            }
            swap(temp[dpos],temp[tpos]);
        }
        if (tpos%3!=2)
        {
            dpos = tpos+1;
            swap(temp[dpos],temp[tpos]);
            tcan = cantor(temp);
            if (!used[tcan])
            {
                used[tcan] = true;
                memcpy(que[++ed].num,temp,sizeof(temp));
                que[ed].pos = dpos;
                que[ed].step = tstep+1;
            }
            swap(temp[dpos],temp[tpos]);
        }
        if (used[gval])
        {
            cout << tstep+1 << endl;
            //system("pause");
            exit(0);
        }
    }
}
int main()
{
    load();
    work();
    return 0;
}
//283104765
