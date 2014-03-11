/**
 * Description:
 * ProblemName:
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

int n;
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    printf("%d\n", (n*n+1)/2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i&1) == (j&1))
                putchar('C');
            else
                putchar('.');
        }
        puts("");
    }
    return 0;
}
