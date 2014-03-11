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

int main() {
    for (int i = 1; i <= 33; ++i)
        for (int j = 1; j <= 50; ++j) {
            int k = 100-i-j;
            if (0 == k%3) {
                if (3*i+2*j+k/3 == 100)
                    printf("%d %d %d\n", i, j, k);
            }
        }
}