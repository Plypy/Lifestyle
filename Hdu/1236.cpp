/**
 * Description: Simple sorting problem
 * Source: hdu1236
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXM = 15;
const int MAXL = 30;
struct Stu {
    char id[MAXL];
    int grade;
    bool operator<(const Stu &t) const {
        if (grade != t.grade)
            return grade>t.grade;
        return strcmp(id,t.id) < 0;
    }
};

Stu stu[MAXN];
int val[MAXM];
char buf[MAXL];
int n, m, g;
int main(int argc, char const *argv[]) {
    while (true) {
        scanf("%d", &n);
        if (0 == n)
            break;
        scanf("%d%d", &m, &g);
        for (int i = 0; i < m; ++i)
            scanf("%d", val+i);
        int ct = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%s%d", buf, &num);
            int sum = 0;
            for (int j = 0; j < num; ++j) {
                int t;
                scanf("%d", &t);
                sum += val[t-1];
            }
            if (sum < g)
                continue;
            strcpy(stu[ct].id, buf);
            stu[ct++].grade = sum;
        }
        sort(stu,stu+ct);
        printf("%d\n", ct);
        for (int i = 0; i < ct; ++i) {
            printf("%s %d\n", stu[i].id, stu[i].grade);
        }
    }
    return 0;
}