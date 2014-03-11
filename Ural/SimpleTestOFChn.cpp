#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
#define x first
#define y second

typedef pair<int,int> pi;
const int MAXN = 52;
const int NUM = 13;
pi tile[MAXN];
pi person[4][NUM];
string color[4] = {"红桃", "方块", "黑桃", "梅花"};

void ptcard(const pi &a) {
    cout << color[a.x];
    if (a.y < 10)
        cout << a.y+1;
    else
        cout << char('J'+a.y-10);
    cout << endl;
}
void print() {
    for (int i = 0; i < 4; ++i) {
        cout << "person " << i << endl;
        for (int j = 0; j < NUM; ++j) {
            ptcard(person[i][j]);
        }
        cout << endl;
    }
}
void shuffle() {
    for (int i = 0; i < MAXN; ++i) {
        tile[i].x = i/NUM;
        tile[i].y = i%NUM;
    }

    srand(time(0));
    for (int i = 0; i < MAXN; ++i) {
        int a = rand()%MAXN, b = rand()%MAXN;
        swap(tile[a],tile[b]);
    }

    for (int i = 0; i < MAXN; ++i) {
        person[i/NUM][i%NUM] = tile[i];
    }
    for (int i = 0; i < 4; ++i)
        sort(person[i],person[i]+NUM);
}
int main() {
    cout << "你好" << endl;
//    ios_base::sync_with_stdio(false);
//    wcout.imbue(locale(""));
//    wstring a(L"你");
//    wcout << a << endl;
    shuffle();
    // print();
    return 0;
}
