#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
const int MAXN = 105;

vector<int> one, two;
int n;
void load() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == 1)
            one.push_back(b);
        else
            two.push_back(b);
    }
}
void work() {
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    one.push_back(0);
    two.push_back(0);
    reverse(one.begin(),one.end());
    reverse(two.begin(),two.end());
    int s1 = accumulate(one.begin(), one.end(), 0);
    int s2 = accumulate(two.begin(), two.end(), 0);

    int ans = 1000000;
    int s = 0;
    for (int i = 0; i < one.size(); ++i) {
        s += one[i];
        int apd = 0;
        for (int j = 0; j < two.size(); ++j) {
            apd += two[j];
            if (i+2*j >= s1+s2-s-apd) {
                if (ans > i+2*j)
                    ans = i+2*j;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    load();
    work();
    return 0;
}
