// if n=3 then we can just check if (a[1]^a[2]^a[3] = 0)
// if the condition above holds, then it's a losint state
// otherwise it's a winning state
// just like ordinary NIM games
// as for n = 2, just use simple DP solution
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=310;
const int MGO=305;

bool wins2[MAXN][MAXN];
void calc2() {
    for(int i=0; i<MGO; ++i)
        for(int j=max(i,1); j<MGO; ++j) {
            for(int I=0; I<i; ++I)
                if(wins2[I][j]==false) {
                    wins2[i][j]=true;
                    break;
                }
            for(int J=0; J<j and wins2[i][j]==false; ++J)
                if(wins2[i][J]==false) {
                    wins2[i][j]=true;
                    break;
                }
            for(int K=1; K<=min(i,j) and wins2[i][j]==false; ++K)
                if(wins2[i-K][j-K]==false) {
                    wins2[i][j]=true;
                    break;
                }
            wins2[j][i]=wins2[i][j];
        }
}

int main() {
    int n;
    cin>>n;
    if(n==1) {
        int x;
        cin>>x;
        if(x==0)
            cout<<"BitAryo"<<endl;
        else
            cout<<"BitLGM"<<endl;
    } else if(n==2) {
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        calc2();
        if(wins2[x][y])
            cout<<"BitLGM"<<endl;
        else
            cout<<"BitAryo"<<endl;
    } else {
        int x,y,z;
        cin>>x>>y>>z;
        if((x^y^z)==0)
            cout<<"BitAryo"<<endl;
        else
            cout<<"BitLGM"<<endl;
    }
    return 0;
}
