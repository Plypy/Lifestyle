#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
const int MAXP = 1000001;
bool notp[MAXP];
vector<int> plis;

void init() {
    for (int i = 2; i < MAXP; ++i)
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = i*2; j < MAXP; j += i)
                notp[j] = true;
        }
}

int main() {
    init();
    int pnum = plis.size();
    long long t;
    while (true) {
        cin >> t;
        if (t < 0)
            break;
        for (int i = 0; i < pnum; ++i) {
            while (0 == t%plis[i]) {
                cout << "    " << plis[i] << endl;
                t /= plis[i];
            }
        }
        if (t > 1)
            cout << "    " << t << endl;
        cout << endl;
    }
    return 0;
}
