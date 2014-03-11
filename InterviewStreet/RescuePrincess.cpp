#include <iostream>
#include <vector>
using namespace std;
/* Head ends here */
void print(string str, int num) {
    for (int i = 0; i < num; ++i)
        cout << str <<endl;
}
void displayPathtoPrincess(int n, vector <string> grid){
    int sx, sy;
    int tx, ty;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'm')
                sx = j, sy = i;
            if (grid[i][j] == 'p')
                tx = j, ty = i;
        }
    if (sx > tx) {
        print("LEFT", sx-tx);
    } else if (sx < tx) {
        print("RIGHT", tx-sx);
    }
    if (sy > ty) {
        print("UP", sy-ty);
    } else if (sy < ty) {
        print("DOWN", ty-sy);
    }
}
/* Tail starts here */
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
