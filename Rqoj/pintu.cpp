#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
struct pos
{
    int x,y;
};
void find(int);
void print();
int tmp,tot, ct;
bool bo;
int f[6][6][6];
int a[30][30];
int n;
pos c[6];
int main()
{
    double len;
    char ch;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i].x >> c[i].y;
        cin.get();
        for(int j=1;j<=c[i].x;j++)
        {
            for(int k=1;k<=c[i].y;k++)
            {
                cin.get(ch);
                if(ch=='0')
                    f[i][j][k]=0;
                else
                {
                    tot++;
                    f[i][j][k]=i;
                }
            }
            cin.get();
        }
    }
    len=sqrt(tot*1.0);
    tmp=(int)len;
    if(len-tmp)
    {
        cout <<"No solution possible";
        return 0;
    }
    if(n==1 && tmp==1)
    {
        cout <<'1'<<endl;
        return 0;
    }
    find(1);
    cout <<"No solution possible";
    return 0;
}
void print()
{
    for(int i=1;i<=tmp;i++)
    {
        for(int j=1;j<=tmp;j++)
            cout <<a[i][j];
        cout <<endl;
    }            
    exit(0);
}
void find(int k)
{
    ct++;
    if(ct>n)
    {
        for (int i=1;i<=tmp;i++)
            for (int j=1;j<=tmp;j++)
                if(a[i][j]==0)
                    bo=true;
        if (bo==0)
            print();
        ct--;
    }
    for (int i=1;i<=(tmp-c[k].x)+1;i++)
        for (int j=1;j<=(tmp-c[k].y)+1;j++)
        {
            int m=0;
            for (int ii=i;ii<=(i+c[k].x)-1;ii++)
                for (int jj=j;jj<=(j+c[k].y)-1;jj++)
                    if (a[ii][jj]==0||f[k][ii-i+1][jj-j+1]==0)
                        continue;
                    else 
                    {
                        m=1;
                        break;
                    }
            if(!m)
            {
                for(int ii=i;ii<=(i+c[k].x)-1;ii++)
                    for(int jj=j;jj<=(j+c[k].y)-1;jj++)
                        a[ii][jj] = max(a[ii][jj],f[k][ii-i+1][jj-j+1]);
                find(k+1);
                for(int ii=i;ii<=(i+c[k].x)-1;ii++)
                     for(int jj=j;jj<=(j+c[k].y)-1;jj++)
                         if(a[ii][jj]==k)
                            a[ii][jj]=0;
            }
        }
            ct--;
}
/*
输入样例2：
5
2 2
11
11
2 3
111
100
3 2
11
01
01
1 3
111
1 1
1
输出样例2：
1133
1153
2223
2444
*/
