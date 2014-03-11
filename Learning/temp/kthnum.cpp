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

const int MAXN = 10005;
int ar[MAXN];
int getrand(int l, int r) {
    return l+rand()%(r-l+1);
}
int find(int l, int r, int k) {
    int m = getrand(l, r);
    swap(ar[m],ar[l]);
    int pivot = ar[l];
    m = l;
    for (int i = l+1; i <= r; ++i) {
        if (ar[i] >= pivot) {
            ar[m] = ar[i];
            ar[i] = ar[m+1];
            ++m;
        }
    }
    ar[m] = pivot;
    int tk = m-l+1;
    if (tk == k)
        return ar[m];
    if (tk > k)
        return find(l,m,k);
    return find(m+1,r,k-tk);
}
int n, k;
int main() {
    srand(time(0));
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    while (cin >> k)
        cout << find(0,n-1,k) << endl;
}