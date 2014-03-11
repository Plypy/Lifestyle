/*
  Description: Advanced Euclid Algorithm
*/
#include <iostream>
using namespace std;
void AdvGcd(unsigned int c, unsigned int d)//
{// We must ensure two equations, which are a1*n+b1*m=c a*n+b*m=d, correct when the algorithm runs.
    int n, m;
    n = c, m = d;
    int a,a1, b,b1;
    a = b1 = 0;
    a1 = b = 1;
    int q, r;
    int t;
    while (true)
    {
        q = c/d;
        r = c%d;
        if (!r)
            break;
        c = d;
        d = r;
        t = a1;
        a1 = a;
        a = t-q*a;
        
        t = b1;
        b1 = b;
        b = t-q*b;
    }
    cout << a << "*" << n << " + " << b << "*" << m << "=" << d <<endl;
}
int main()
{
    unsigned int a, b;
    while (cin >> a >> b)
        AdvGcd(a,b);
    return 0;
}
