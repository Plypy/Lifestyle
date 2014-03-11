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
const int INF = 1<<30;
bool num[20];
bool up, down;
bool comb;
int from, to;
void load() {
    for (int i = 1; i <= 3; ++i)
        cin >> num[i];
    cin >> up;
    for (int i = 4; i <= 6; ++i)
        cin >> num[i];
    cin >> down;
    for (int i = 7; i <= 9; ++i)
        cin >> num[i];
    cin >> comb >> num[0];
    cin >> from >> to;
}
int getUp(int a, int b) {
    if (a == b)
        return 0;
    if (up)
        return (b-a+100)%100;
    return INF;
}
int getDown(int a, int b) {
    if (a == b)
        return 0;
    if (down)
        return (a-b+100)%100;
    return INF;
}
int main() {
    load();
    int ans = INF;
    if (from == to) {
        ans = 0;
    } else {
        if (up) {
            ans = min(ans,getUp(from,to));
        }
        if (down) {
            ans = min(ans,getDown(from,to));
        }
        for (int i = 0; i < 10; ++i)
            if (num[i]) {
                ans = min(ans,1+getUp(i,to));
                ans = min(ans,1+getDown(i,to));
            }
        if (comb) {
            for (int i = 1; i < 10; ++i)
                for (int j = 1; j < 10; ++j)
                    if (num[i] && num[j]) {
                        ans = min(ans,3+getUp(i*10+j,to));
                        ans = min(ans,3+getDown(i*10+j,to));
                    }
        }
    }
    if (INF == ans) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
