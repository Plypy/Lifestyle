/*
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long n, sum;
pair<long long, long long> b[100002];

inline void getInt(long long &x) {
    char c;
    for (c = getchar(); c > '9' || c < '0'; c = getchar());
    for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
}

inline bool calc(long long p) {
    for (long long i = n, last = sum - p; (i > 0) && (b[i].first >= last); --i) {
        last -= b[i].second;
        if (last <= 0) 
            return true;
    }
    return false;
}

int main() {
    // std::ios::sync_with_stdio(false);
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    while (cin >> n) {
        sum = 0;
        for (long long j = 1; j <= n; ++j) {
            getInt(b[j].second);
            getInt(b[j].first);
            sum += b[j].second;
            b[j].first += b[j].second;
        }
        sort(b + 1, b + n + 1);
        long long L = 0, R = sum;
        for (long long M = (L + R) >> 1; L < R; M = (L + R) >> 1) {
            if (!calc(M)) L = M + 1;
            else R = M;
        }
        cout << L << endl;
    }
    return 0;
}
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
long long n, sum;
pair<long long, long long> b[100002];
inline bool calc(long long p) {
    for (long long i = n, last = sum - p; (i > 0) && (b[i].first >= last); --i) {
        last -= b[i].second;
        if (last <= 0) 
            return true;
    }
    return false;
}
int main() {
    while (cin >> n) {
        sum = 0;
        for (long long j = 1; j <= n; ++j) {
            cin >> b[j].second >> b[j].first;
            sum += b[j].second;
            b[j].first += b[j].second;
        }
        sort(b + 1, b + n + 1);
        long long L = 0, R = sum;
        for (long long M = (L + R) >> 1; L < R; M = (L + R) >> 1) {
            if (!calc(M)) L = M + 1;
            else R = M;
        }
        cout << L << endl;
    }
    return 0;
}
