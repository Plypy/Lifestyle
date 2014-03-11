// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    Vector result(20, 10);
    cout << result << endl;
    cout << -result << endl;
    cout << "Bye!\n";
    cin.get();
    return 0; 
}
