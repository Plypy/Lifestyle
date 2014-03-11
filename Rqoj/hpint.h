// hpint.h
#include <iostream>
using namespace std;
class hpint
{
private:
    string num;
public:
    hpint();
    hpint(const char array[]);
    hpint(const hpint & copy);
    const hpint & operator=(const hpint & hi);
    ~hpint();
    
    const hpint & operator+(const hpint & hi2);
    const hpint & operator-(const hpint & hi2);
    const hpint & operator*(const hpint & hi2);
    const hpint & operator/(const hpint & hi2);
    const hpint & operator%(const hpint & hi2);
    const hpint & operator+(const int  i);
    const hpint & operator-(const int  i);
    const hpint & operator*(const int  i);
    const hpint & operator/(const int  i);
    const hpint & operator%(const int  i);
    
    friend ostream & operator<<(ostream & os, const hpint & hi);
    friend istream & operator>>(istream & is, const hpint & hi);
    friend hpint & operator+(const int i, const hpint & hi);
    friend hpint & operator*(const int i, const hpint & hi);
};
