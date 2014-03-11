#include <iostream>

using namespace std;

int x,y,m;

int main() {
    cin>>x>>y;
    // use the inequalities to judge which part the point will belong to.
    if(y>x && x>=-y)
        m=-2+y*4;
    if(y<x && x<=-y+1)
        m=-y*4;
    if(y<=x && x>-y+1)
        m=-3+x*4;
    if(y>=x && x<-y)
        m=-1-4*x;
    cout<<m<<endl;
    return 0;
}
