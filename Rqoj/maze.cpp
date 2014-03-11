#include <iostream>
#include <fstream>
using namespace std;

int M,N;
bool **Maze;

void solve();
void load();

int main()
{
    load();
    solve();
    return 0;
}

void load()
{
    ifstream fin;
    fin.open("maze.in");
    fin >> M >> N;
    Maze = new bool*[M];
    for (int i = 0; i < M; i++)
        Maze[i] = new bool[N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            fin >> Maze[i][j];
    fin.close();
} 
void solve()
{
    ofstream fout;
    fout.open("maze.out");
    
    fout << ans;
}
    
