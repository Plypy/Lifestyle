#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans;
    if (n >= 1000)
        ans = "legion";
    else if (n >= 500)
        ans = "zounds";
    else if (n >= 250)
        ans = "swarm";
    else if (n >= 100)
        ans = "throng";
    else if (n >= 50)
        ans = "horde";
    else if (n >= 20)
        ans = "lots";
    else if (n >= 10)
        ans = "pack";
    else if (n >= 5)
        ans = "several";
    else
        ans = "few";
    cout << ans << endl;
    return 0;
}
