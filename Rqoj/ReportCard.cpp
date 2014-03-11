#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int MAXN = 130001;
struct student
{
    int mark;
    string name;
} list[MAXN];
int num[15];
string* ans[10001];
int n;
int cmp(const void*a,const void*b)
{
    if (((student*)a)->name < ((student*)b)->name)
        return -1;
    return 1;
}
int main()
{
    scanf("%d",&n);
    int tmp;
    char ch[35];
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",ch);
        list[i].name = ch;
        scanf("%d",&tmp);
        num[tmp/10]++;
        list[i].mark = tmp;
    }
    printf("1~9 10~19 20~29 30~39 40~49 50~59 60~69 70~79 80~89 90~99 100~109 110~119 120~129 130~139 140~149\n");
    for (int i = 0; i < 14; i++)
        printf("%d ", num[i]);
    printf("%d\n", num[14]);
    qsort(list+1,n,sizeof(student),cmp);
    int ac = 0;
    for (int i = 1; i <= n; i++)
    {
        printf("%s %d\n",list[i].name.c_str(),list[i].mark);
        if (list[i].mark == 150)
            ans[++ac] = &list[i].name;
    }
    printf("%d\n",ac);
    if (ac)
    {
        for (int i = 1; i < ac; i++)
            printf("%s\n",ans[i]->c_str());
        printf("%s",ans[ac]->c_str());
    }
    else
        printf("No");
    return 0;
}
