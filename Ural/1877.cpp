#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int even, odd;
int main() {
    cin >> even >> odd;
    if ((odd&1) || (!(even&1)))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
