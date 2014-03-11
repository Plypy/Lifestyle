#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    while (true) {
        char ch= cin.get();
        if (!cin)
            break;
        if (ch != '\n')
            cout << char(ch-7);
        else
            cout << endl;
    }
    return 0;
}
