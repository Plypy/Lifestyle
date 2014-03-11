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


int main(int argc, char const *argv[]) {
    int a, b;
    scanf("%d%d", &a, &b);
    int c = max(b*2+40,39*2+40+2*(a-40)+1);
    printf("%d\n", c);
    return 0;
}