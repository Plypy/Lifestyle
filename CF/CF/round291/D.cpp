#include <iostream>
#include <deque>
#include <cstdio>
#include <string>
using namespace std;

const int MAXM = 5;
const int MAXN = 100005;

int ar[MAXN][MAXM];
deque<int> que[MAXM];
int n, m, k;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int left = 0;
    int maxlen = 0;
    int ans[MAXM] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &ar[i][j]);
            while (que[j].size() && ar[que[j].back()][j] <= ar[i][j]) {
                que[j].pop_back();
            }
            que[j].push_back(i);
        }

        while (true) {
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                if (que[j].size()) {
                    sum += ar[que[j].front()][j];
                }
            }
            if (sum <= k) {
                break;
            }
            ++left;
            for (int j = 0; j < m; ++j) {
                while (que[j].size() && que[j].front() < left) {
                    que[j].pop_front();
                }
            }
        }

        if (i-left+1 > maxlen) {
            maxlen = i-left+1;
            for (int j = 0; j < m; ++j) {
                ans[j] = ar[que[j].front()][j];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << (i == m-1 ? '\n' : ' ');
    }
}
