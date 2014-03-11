#include <iostream>
using namespace std;
int go[8][2] = {
    {2,1},{2,-1},{-2,1},{-2,-1},
    {1,2},{1,-2},{-1,2},{-1,-2}
};
bool check(int x, int y)
{
    if (x < 1 || x > 8)
        return false;
    if (y < 1 || y > 8)
        return false;
    return true;
}
int main()
{
    int n;
    int x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        x = ch-'a'+1;
        cin >> y;
        int t = 0;
        for (int i = 0; i < 8; i++)
            if (check(x+go[i][0],y+go[i][1]))
                ++t;
        cout << t << endl;
    }
    return 0;
}
