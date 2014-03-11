/*
    ID : jake1994
    PROG : fence9
    LANG : C++
*/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
inline int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a;
        a = b;
        b = c%b;
    }
    return a;
}
int main()
{
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");
    int n,m,p,b=0,s;
    fin>>n>>m>>p;
    s=(m*p)>>1;
    b = gcd(n,m);
    if (n!=p) 
        b += gcd(abs(n-p),m);
    else 
        b += m;
    b += p;
    fout<<s+1-(b>>1)<<endl;
    return 0;
}
