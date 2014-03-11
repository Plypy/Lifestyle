#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <iomanip>

#define DEBUG
using namespace std;
const int NAMELEN = 35;
int sum;
map<string, int> woods_map;
void load() {
    char name[NAMELEN] = "";
    while (gets(name)) {
        ++woods_map[name];
        ++sum;
    }
}
void work() {
    double tot = sum;
    for (map<string, int>::const_iterator c_itr = woods_map.begin(), terminal = woods_map.end();
        c_itr != terminal; ++c_itr)
            printf("%s %.4lf\n", c_itr->first.c_str(), 100.0*c_itr->second/tot);
}
int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    load();
    work();
    return 0;
}
