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
    vector<int> vec;
    vec.push_back(-1);
    for (int i = 0; i < 10; ++i)
        vec.insert(++vec.begin(),i);

    for (vector<int>::reverse_iterator titr = vec.rbegin(); titr != vec.rend(); ++titr)
        cout << *titr << endl;
    return 0;
}