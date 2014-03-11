#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Point {
    int x, y, z;
}pt1,pt2,pt3,pt4;
istream &operator>>(istream &is, Point &t) {
    is >> t.x >> t.y >> t.z;
    return is;
}
int main() {
    cin >> pt1 >> pt2 >> pt3 >> pt4;
    int vol = (pt2.x-pt1.x)*(pt2.y-pt1.y)*(pt2.z-pt1.z)
            + (pt4.x-pt3.x)*(pt4.y-pt3.y)*(pt4.z-pt3.z);
    if (!(pt3.x >= pt2.x || pt4.x <= pt1.x
     || pt3.y >= pt2.y || pt4.y <= pt1.y
     || pt3.z >= pt2.z || pt4.z <= pt1.z)) {
            int x1 = max(pt1.x,pt3.x);
            int x2 = min(pt2.x,pt4.x);
            int y1 = max(pt1.y,pt3.y);
            int y2 = min(pt2.y,pt4.y);
            int z1 = max(pt1.z,pt3.z);
            int z2 = min(pt2.z,pt4.z);
            vol -= (x2-x1)*(y2-y1)*(z2-z1);
    }
    cout << vol << endl;
//    system("pause");
    return 0;
}
