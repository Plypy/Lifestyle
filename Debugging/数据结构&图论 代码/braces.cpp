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
#include <stack>
using namespace std;


int main() {
    string str;
    cin >> str;
    stack<char> stk;
    bool flag = true;
    for (int i = 0; i < str.size(); ++i) {
        if ('(' == str[i])
            stk.push(str[i]);
        else {
            if (stk.empty()) {
                flag = false;
                break;
            }
            stk.pop();
        }
    }
    if (stk.size())
        flag = false;
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}