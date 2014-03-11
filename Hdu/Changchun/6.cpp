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


int n, k;
int main(int argc, char const *argv[]) {
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        if ((n-1)%(k+1) == 0) {
            cout << "Jiang" << endl;
        } else {
            cout << "Tang" << endl;
        }
    }
    return 0;
}