/*
    ID : jake1994
    PROG : wissqu
    LANG : C++
*/
//Note
//���Ⱪ�Ѽ��ɣ�ûɶ��������
//������Ҫ��ס���ǣ��������˰� 
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("wissqu.in");
ofstream fout("wissqu.out");
int num[5] = {3,3,3,4,3};
int map[6][6];
void load()
{
    memset(map,0xff,sizeof(map));
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            char ch;
            fin >> ch;
            map[i][j] = ch-'A';
        }
}
struct move
{
    int row, col;
    char type;
} mv[16];
bool used[5][5];
bool check(int r, int c, int t)
{
    if (used[r][c])
        return false;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (map[r+i][c+j] == t)
                return false;
    return true;
}
void output()
{
    for (int i = 0; i < 16; i++)
        fout << mv[i].type << ' ' << mv[i].row << ' ' << mv[i].col << endl;
}
int sum = 0;
void dfs(int step, int type)
{
    if (step == 16)
    {
        if (!sum)
            output();
        sum++;
        return;
    }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (check(i,j,type))
            {
                if (!sum)
                {
                    mv[step].row = i;
                    mv[step].col = j;
                    mv[step].type = type+'A';
                }
                int backup = map[i][j];
                used[i][j] = true;
                map[i][j] = type;
                num[type]--;
                if (step == 15)                 //���簡 ����һ��СС�ļ���...����Ū�˽�һ��Сʱ 
                    dfs(step+1,0);              //�ɼ�ϸ���ж�ô��Ҫ 
                else
                    for (int k = 0; k < 5; k++)
                        if (num[k])
                            dfs(step+1,k);
                used[i][j] = false;
                num[type]++;
                map[i][j] = backup;
            }
}
int main()
{
    load();
    dfs(0,3);//����D
    fout << sum << endl;
    return 0;
}
