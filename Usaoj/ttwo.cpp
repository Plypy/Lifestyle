/*
ID: jake1994
PROG: ttwo
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
const short direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
char map[12][12];
bool used[11][11][4][11][11][4] = {false};
int count;
class T
{
public:
	int x,
		y,
		dire;//up:0 right:1 down:2 left:3
	T() 
	{
		dire = 0;
	}
	void go()
	{
		if(map[direction[dire][0] + x][direction[dire][1] + y] == '*')
			dire = (dire+1)%4;
		else x += direction[dire][0],
			 y += direction[dire][1];
	}
 
};
 
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
T F,C;
 
void input()
{
	string in;
	for(int i=0; i<=11; i++)
		map[0][i] = '*',
		map[11][i] = '*';
	for(int i=1; i<=10; i++)
	{
		fin >> in;
		map[i][0] = '*';
		map[i][11] = '*';
		for(int j=1; j<=10; j++)
		{
			if(in[j-1] != 'C' && in[j-1] != 'F')
				map[i][j] = in[j-1];
			else 
			{
				map[i][j] = '.';
				if(in[j-1] == 'F')
					F.x = i,
					F.y = j;
				else C.x = i,
					 C.y = j;
			}
 
		}
	}
}
 
int main()
{
	input();
	count = 0;
	while(true)
	{
		if(used[F.x][F.y][F.dire][C.x][C.y][C.dire])
		{
			fout << 0 << endl;
			return 0;
		}
		used[F.x][F.y][F.dire][C.x][C.y][C.dire] = true;
		if(F.x == C.x && F.y == C.y)
		{
			fout << count << endl;
			return 0;
		}
		F.go();
		C.go();
		count++;
	}
    return 0;
}
