/**
 * Author: Ply_py
 */
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

const int N = 10000;
const int MAXN = N+5;

int data[MAXN];
int size;
inline int lson(int a) {
    return a<<1;
}
inline int rson(int a) {
    return lson(a)+1;
}
inline int fa(int a) {
    return a>>1;
}
int heapfy(int pos) {
    while (true) {
        int l = lson(pos);
        int r = rson(pos);
        int m = pos;
        if (l <= size && data[l] < data[m]) {
            m = l;
        }
        if (r <= size && data[r] < data[m]) {
            m = r;
        }
        if (m == pos)
            break;
        swap(data[pos],data[m]);
        pos = m;
    }
}
void update(int pos, int val) {
    data[pos] = val;
    while (pos != 1 && data[fa(pos)] > data[pos]) {
        swap(data[fa(pos)],data[pos]);
        pos = fa(pos);
    }
}
void push(int a) {
    update(++size,a);
}
int extract() {
    int ret = data[1];
    swap(data[1],data[size--]);
    heapfy(1);
    return ret;
}

int main() {
    for (int i = 100; i; --i)
        push(i);
    while (size) {
        cout << extract() << endl;
    }
    return 0;
}
