#include <fstream>
#include <iostream>
#include <string>
ifstream fin("family.in");
ofstream fout("family.out");
#define cout fout
const int MAX = 300+5;
struct num{
    int len;
    char n[MAX];
};
num p[MAX][MAX];
int st[MAX][MAX];
int st[MAX]{MAX] = {0};
int parent[MAX][MAX] = {0};
int n, m;
int g[MAX][MAX];
void out(num& op)
{
    if(op
