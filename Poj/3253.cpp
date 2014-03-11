/**
 * Description: Huffman Tree problem
 * Source: POJ 3253
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

const int MAXN = 20005;
typedef long long ll;
int n;
int main() {
    scanf("%d", &n);
    priority_queue<ll, vector<ll>, greater<ll> > que;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        que.push(tmp);
    }
    long long ans = 0;
    while (que.size() > 1) {
        long long a = que.top();
        que.pop();
        long long b = que.top();
        que.pop();
        long long tmp = a+b;
        que.push(tmp);
        ans += tmp;
    }
    printf("%lld\n", ans);
}