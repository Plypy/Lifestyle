#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int  MAX=1001;
int pos[MAX][2];
struct Radar
{
    double left;
    double right;
    Radar()
    {
        left = 0;
        right = 0;
    }
};
Radar radar[MAX];
const
bool operator < (const Radar &a, const Radar &b)
{
    return a.left<b.left;
}
int main ()
{
    ios::sync_with_stdio(false);
    int n,d,t=1;
    while(cin>>n>>d)
    {
        bool flag=true;
        if(n == 0 && d == 0)
            break;
        if(d<=0)
        {
            flag=false;
        }
        for(int i=0;i<n;i++)
        {
            cin>>pos[i][0]>>pos[i][1];
            double temp=(double)d*d-pos[i][1]*pos[i][1];
            if(temp<0)
            {
                flag=false;
            }
            else if(flag)
            {
                radar[i].left=pos[i][0]-sqrt(temp);
                radar[i].right=pos[i][0]+sqrt(temp);
            }
        }
        if(!flag)
            cout<<"Case "<<t<<": -1"<<endl;
        else
        {
            sort(radar,radar+n);
            double prad=radar[0].right;
            int number=1;
            for(int i=1;i<n;i++)
            {
                if(prad<radar[i].left)
                {
                    prad=radar[i].right;
                    number++;
                }
                else if(prad>radar[i].right)
                    prad=radar[i].right;
            }
            cout<<"Case "<<t<<": "<<number<<endl;
        }
        t++;
    }
    return 0;
}
