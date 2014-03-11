/*
    ID : jake1994
    PROG : rect1
    LANG : C++
*/
//Note
//矩形切割法
#include <iostream>
#include <fstream> 
using namespace std;
const int MAXN = 2505;
ifstream fin("rect1.in");
ofstream fout("rect1.out");
int lx[MAXN], ly[MAXN], rx[MAXN], ry[MAXN];
int color[MAXN], area[MAXN];
int n, a, b;;
void cover(int x1, int y1, int x2, int y2, int col, int hit)
{//如果递归调用时除了判断终止的参量外其他参量均没有变化，可以用循环的方法代替递归，具体如下 
    while (hit <= n && (lx[hit]>=x2 || x1>=rx[hit] || ly[hit]>=y2 || y1>=ry[hit])) 
        hit++;
    if (hit > n)
    {
        area[col] += (x2-x1)*(y2-y1);
        return ;
    }
    if (x1 < lx[hit])
    {
        cover(x1,y1,lx[hit],y2,col,hit+1);
        x1 = lx[hit];
    }
    if (x2 > rx[hit])
    {
        cover(rx[hit],y1,x2,y2,col,hit+1);
        x2 = rx[hit];
    }
    if (y1 < ly[hit])
        cover(x1,y1,x2,ly[hit],col,hit+1);
    if (y2 > ry[hit])
        cover(x1,ry[hit],x2,y2,col,hit+1);
}
int main()
{
    fin >> rx[0] >> ry[0] >> n;
    color[0] = 1;
    int bound = 0;
    for (int i = 1; i <= n; ++i)
    {
        fin >> lx[i] >> ly[i] >> rx[i] >> ry[i] >> color[i];
        if (color[i] > bound)
            bound = color[i];
    }
    for(int i = n ; i>=0 ; i--)
        cover(lx[i],ly[i],rx[i],ry[i],color[i],i+1);
    for (int i = 1; i <= bound; i++)
        if (area[i])
            fout << i << ' ' << area[i] << endl;
    fin.close();
    fout.close();
    return 0;
}
