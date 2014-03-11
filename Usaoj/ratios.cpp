/*
    ID : jake1994
    PROG : ratios
    LANG : C++
*/
//此题其实就是解一个四元不定线性方程的最简整数解
//我的解法使用了克拉默法则，计算一个矩阵的行列式即可 
#include <iostream>
#include <fstream>
using namespace std;
int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = b;
        b = a%b;
        a = c;
    }
    return a;
}
int main()
{
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");
    int x, y, z;
    int x1, y1, z1;
    int x2, y2, z2;
    int x3, y3, z3;
    fin >> x >> y >> z;
    fin >> x1 >> y1 >> z1;
    fin >> x2 >> y2 >> z2;
    fin >> x3 >> y3 >> z3;
    int d, d1, d2, d3;
    d = x1*(y2*z3-z2*y3)-x2*(y1*z3-z1*y3)+x3*(y1*z2-z1*y2);
    d1 = x*(y2*z3-z2*y3)-x2*(y*z3-z*y3)+x3*(y*z2-z*y2);
    d2 = x1*(y*z3-z*y3)-x*(y1*z3-z1*y3)+x3*(y1*z-z1*y);
    d3 = x1*(y2*z-z2*y)-x2*(y1*z-z1*y)+x*(y1*z2-z1*y2);
    if (d < 0)
    {
        d = -d;
        d1 = -d1;
        d2 = -d2;
        d3 = -d3;
    }
    if (d1 < 0 || d2 < 0 || d3 < 0)
        fout << "NONE" << endl;
    else
    {
        int div = gcd(d,gcd(d1,gcd(d2,d3)));
        fout << d1/div << ' ' << d2/div << ' ' << d3/div << ' ' << d/div << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
