#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;
const int MAXSIZE = 100;



int sop[MAXSIZE];
int snum[MAXSIZE];


double eval(string expr) {
    eval += '#';
    
}


int main() {
    string expr;
    cout << setprecision(2);
    while (getline(cin,expr))
        cout << eval(expr) << endl;
    return 0;
}
