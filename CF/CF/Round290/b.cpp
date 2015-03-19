#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int MAXN = 305;
const int MAXD = 1000007;
const int STEP = 3;

int N;

struct Data
{
     int num;
     int cost;
     Data(int a = 0, int b = 0): num(a), cost(b) {}
     bool operator<(const Data &t) const {
          return cost > t.cost;
     }
} data[MAXN];

int gcd(int a, int b)
{
     int c;
     while (b) {
          c = a;
          a = b;
          b = c%b;
     }
     return a;
}

int main()
{
     int i;
     scanf("%d", &N);
     priority_queue<Data> que;
     for (i = 0; i < N; ++i) {
          scanf("%d", &data[i].num);
     }
     for (i = 0; i < N; ++i) {
          scanf("%d", &data[i].cost);
          que.push(data[i]);
     }
     int ans = -1;
     map<int, int> used;
     while (que.size()) {
          int num = que.top().num;
          int cost = que.top().cost;
          que.pop();
          if (1 == num) {
               ans = cost;
               break;
          }
          if (used.count(num)) {
               continue;
          }
          used[num] = cost;
          for (map<int, int>::iterator it = used.begin(); it != used.end(); ++it) {
               int tnum = gcd(num, it->first);
               int tcost = cost+it->second;
               if (!used.count(tnum)) {
                    que.push(Data(tnum, tcost));
               }
          }
     }
     printf("%d\n", ans);
}
