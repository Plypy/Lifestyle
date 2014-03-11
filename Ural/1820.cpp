#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << max(2,(n*2+k-1)/k) << endl;
    return 0;
}
