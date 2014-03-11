/**
 * Description:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;


char day[7][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

typedef long long ll;
int st;
ll len, spd;
char buf[20];

bool load() {
    double a, b;
    if (EOF == scanf("%s%lf%lf", buf, &a, &b))
        return false;
    // cout << a << endl;
    len = (ll)a*1000;
    // cout << len << endl;
    spd = (ll)(b*1000+0.5);
    for (int i = 0; i < 7; ++i) {
        if (0 == strcmp(buf,day[i])) {
            st = i;
        }
    }
    return true;
}
ll wek;
void work() {

    wek = 8*spd*5+4*2*spd;
    // cout << wek << ' ' << spd << endl;
    int rem = len%wek;
    if (rem == 0) {
        printf("%s\n", day[(st+6)%7]);
        return ;
    }
    for (int i = 0; i < 7; ++i) {
        int d = (st+i)%7;
        if (d < 5) {
            rem -= 8*spd;
        } else {
            rem -= 4*spd;
        }
        if (rem <= 0) {
            printf("%s\n", day[d]);
            break;
        }
    }
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}