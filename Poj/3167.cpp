/**
 * Description: KMP similarly problem
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <stack>
using namespace std;

const int MAXN = 100005;
const int MAXM = 25005;
const int MAXK = 30;

// tarray

int N, M, K;

int tct[MAXK];

int low(int x) {
    return x&-x;
}

int get(int a) {
    int ret = 0;
    while (a) {
        ret += tct[a];
        a -= low(a);
    }
    return ret;
}

void update(int a, int v) {
    while (a <= K) {
        tct[a] += v;
        a += low(a);
    }
}

void trclr() {
    memset(tct, 0, sizeof(tct));
}

int pat[MAXM];
int ar[MAXN];
int lee[MAXM], les[MAXM];
int next[MAXM];

void work() {
    // get lee, les
    trclr();
    for (int i = 0; i < M; ++i) {
        update(pat[i], 1);
        lee[i] = get(pat[i]);
        les[i] = get(pat[i]-1);
    }

    // get next
    trclr();
    int i = 0, j = -1;
    while (i < M) {
        if (-1 == j || (get(pat[i]) == lee[j] && get(pat[i]-1) == les[j])) {
            ++i;
            ++j;
            if (i != M && lee[i] == lee[j] && les[i] == les[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
            if (i != M) {
                update(pat[i], 1);
            }
            next[i] = j;
        } else {
            for (int t = i-j; t < i-next[j]; ++t) {
                update(pat[t], -1);
            }
            j = next[j];
        }
    }
    // match
    trclr();
    vector<int> ans;
    i = 0, j = 0;
    update(ar[0], 1);
    while (i < N) {
        if (-1 == j || (get(ar[i]) == lee[j] && get(ar[i]-1) == les[j])) {
            ++i;
            ++j;
            if (i < N) {
                update(ar[i], 1);
            }
        } else {
            for (int t = i-j; t < i-next[j]; ++t) {
                update(ar[t], -1);
            }
            j = next[j];
        }
        if (j == M) {
            for (int t = i-j; t < i-next[j]; ++t) {
                update(ar[t], -1);
            }
            ans.push_back(i-j);
            j = next[j];
        }
    }
    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; ++i) {
        cout << ans[i]+1 << endl;
    }
}

bool load() {
    cin >> N >> M >> K;
    if (!cin) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        cin >> ar[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> pat[i];
    }
    return true;
}

void clear() {

}

int main() {
    ios::sync_with_stdio(false);
    while (load()) {
        work();
        clear();
    }
}
