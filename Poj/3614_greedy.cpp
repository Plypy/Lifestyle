#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2505;
int c, l;
struct Cow {
    int low, upp;
    bool operator<(const Cow &t) const {
        if (upp != t.upp)
            return upp < t.upp;
        return low < t.low;
    }
} cow[MAXN];
struct Screen {
    int spf, amt;
    bool operator<(const Screen &t) const {
        return spf<t.spf;
    }
} scr[MAXN];
void load() {
    scanf("%d%d", &c, &l);
    for (int i = 1; i <= c; ++i)
        scanf("%d%d", &cow[i].low, &cow[i].upp);
    for (int i = 1; i <= l; ++i)
        scanf("%d%d", &scr[i].spf, &scr[i].amt);
}

bool find(int id) {
    for (int i = 1; i <= l; ++i)
        if (scr[i].amt && cow[id].low <= scr[i].spf && scr[i].spf <= cow[id].upp) {
            --scr[i].amt;
            return true;
        }
    return false;
}

void work() {
    sort(scr+1,scr+l+1);
    sort(cow+1,cow+c+1);
    int ans = 0;
    for (int i = 1; i <= c; ++i)
        if (find(i))
            ++ans;
    printf("%d\n", ans);
}

int main() {
    load();
    work();
    return 0;
}
