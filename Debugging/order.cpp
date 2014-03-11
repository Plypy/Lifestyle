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


void build(string pre, string mid) {
    char rt = pre[0];
    int pos = mid.find(rt);
    int lsize = pos-0;
    if (lsize > 0) {
        build(pre.substr(1,lsize),mid.substr(0,lsize));
    }
    int rsize = mid.size()-lsize-1;
    if (rsize > 0)
        build(pre.substr(lsize+1,rsize),mid.substr(pos+1,rsize));
    putchar(mid[pos]);
}

int main(int argc, char const *argv[]) {
    string a, b;
    cin >> a >> b;
    build(a,b);
    puts("");
    return 0;
}