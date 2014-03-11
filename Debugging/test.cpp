/**
 * Description:
 * Source:
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

struct Node;
typedef Node* nptr;
struct Node {
    int data;
    nptr nxt;
};

void insert(nptr &pos, Node &t) {
    t.nxt = pos->nxt;
    pos = &t;
}

int main() {

}