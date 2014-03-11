//蛮复杂的数学题 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int n, m;
    int ans;
    cin >> n >> m;
    if (1 == n || 1 == m)
        ans = (n+m)/2;
    else if (n*m%3)
        ans = 1;
    else
        ans = 2;
    cout << ans << endl;
    return 0;
}
