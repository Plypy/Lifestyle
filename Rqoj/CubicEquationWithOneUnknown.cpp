/*
  Name: CubicEquationWithOneUnknown.cpp
  Author: Ply_py
  Date: 16-01-11 23:05
  Description: Silly
*/
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double A, B, C;
    double x1, x2, x3;
    A = b*b-3*a*c;
    B = b*c-9*a*d;
    C = c*c-3*b*d;
    double Theta;
    Theta = acos((2*A*b-3*a*B)/(2*sqrt(A*A*A)))/3;
    x1 = (-b-2*sqrt(A)*cos(Theta))/(3*a);
    x2 = (-b+sqrt(A)*(cos(Theta)+sqrt(3)*sin(Theta)))/(3*a);
    x3 = (-b+sqrt(A)*(cos(Theta)-sqrt(3)*sin(Theta)))/(3*a);
    if (x1 > x2)
        swap(x1,x2);
    if (x1 > x3)
        swap(x1,x3);
    if (x2 > x3)
        swap(x2,x3);
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << x1 << ' ' << x2 << ' ' << x3;
    return 0;
}
