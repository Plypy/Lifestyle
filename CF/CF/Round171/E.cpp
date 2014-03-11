#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
char ch;
int main(){
    int x = 0, y = 1;
    int ct = 0;
    while ((ch = getchar()) != '\n') {
        int p = min(x,y)+1;
        if (ch == '1')
            x = p;
        else
            y = p;
        cout << ++ct << ' ' << x << ' ' << y << endl;
    }
    cout << x << endl;
    return 0;
}
