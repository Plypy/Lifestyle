#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class GeneType
{
private:
    int wnum;
    int inum;
    double prob;
public:
    GeneType(int _wnum = 0, int _inum = 0, int _prob = 1):
        wnum(_wnum), inum(_inum), prob(_prob){ }
    double mate(GeneType &t,string &wanted)
    {
        
    }
};
void load()
{
}
void work()
{
}
int main()
{
    load();
    work();
    output();
    return 0;
}

/*
��������1
2
aff btt
am am bm
1 2
2 3
t
��������2
2
aff btt
am am bm
1 2
2 1
t

�������1
0.250000
�������2
wrong
*/
