#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cctype>
#include <bitset>
using namespace std;
const int MAXN = 15;
int ct[MAXN];
int n;
int main()
{
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        char ch = getchar();
        ch -= '0';
        switch (ch) {
        case 0:
        case 1:
            break;
        case 2:
            ct[2]++;
            break;
        case 3:
            ct[3]++;
            break;
        case 4:
            ct[2] += 2;
            ct[3]++;
            break;
        case 5:
            ct[5]++;
            break;
        case 6:
            ct[5]++;
            ct[3]++;
            break;
        case 7:
            ct[7]++;
            break;
        case 8:
            ct[7]++;
            ct[2] += 3;
            break;
        case 9:
            ct[7]++;
            ct[2]++;
            ct[3] += 2;
            break;
        }
    }
    for (int i = 9; i > 1; --i) {
        while (ct[i]) {
            putchar(i+'0');
            --ct[i];
        }
    }
    puts("");
}
