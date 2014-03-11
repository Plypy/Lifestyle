#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
//top front left right back bottom
int turn[24][6] = {
    {1,2,3,4,5,6}, {1,3,5,2,4,6}, {1,5,4,3,2,6}, {1,4,2,5,3,6},
    {2,3,1,6,4,5}, {2,1,4,3,6,5}, {2,4,6,1,3,5}, {2,6,3,4,1,5},
    {3,5,1,6,2,4}, {3,1,2,5,6,4}, {3,2,6,1,5,4}, {3,6,5,2,1,4},
    {4,6,2,5,1,3}, {4,2,1,6,5,3}, {4,1,5,2,6,3}, {4,5,6,1,2,3},
    {5,6,4,3,1,2}, {5,4,1,6,3,2}, {5,1,3,4,6,2}, {5,3,6,1,4,2},
    {6,2,4,3,5,1}, {6,4,5,2,3,1}, {6,5,3,4,2,1}, {6,3,2,5,4,1}
};

bool check(const string &a, const string &b) {
    string c = a;
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 6; ++j)
            c[j] = a[turn[i][j]-1];
        if (b == c)
            return true;
    }
    return false;
}

int main() {
    string buf;
    while (cin >> buf) {
        string a = buf.substr(0,6), b = buf.substr(6,6);
        if (check(a,b))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    return 0;
}
