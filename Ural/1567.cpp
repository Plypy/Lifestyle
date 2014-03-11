#include <iostream>
using namespace std;
const int MAXN = 500;
int cost[MAXN];
void init() {
    cost['a'] = cost['d'] = cost['g'] = cost['j'] = 
    cost['m'] = cost['p'] = cost['s'] = cost['v'] = 
    cost['y'] = cost['.'] = cost[' '] = 1;
    
    cost['b'] = cost['e'] = cost['h'] = cost['k'] = 
    cost['n'] = cost['q'] = cost['t'] = cost['w'] =
    cost['z'] = cost[','] = 2;
    
    cost['c'] = cost['f'] = cost['i'] = cost['l'] =
    cost['o'] = cost['r'] = cost['u'] = cost['x'] = 
    cost['!'] = 3;
}
int main() {
    init();
    int ans = 0;
    while (true) {
        char ch = cin.get();
        if ('\n' == ch)
            break;
        ans += cost[ch];
    }
    cout << ans << endl;
    return 0;
}
