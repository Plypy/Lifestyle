/*
ID:jake1994
LANG:C++
TASK:frac1
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int i,j,k,l,m,n;
int hash[100110][3];
int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)//这个思路太牛叉了...直接把分数转化成小数然后一乘变为整数来检查...如果原来的分子分母没现在的小，就说明 
            if (hash[int((float(j)/i)*100000)][1] == 0 || hash[int((float(j)/i)*100000)][2] > i)//现在的表示形式对于此数值更简 
            {
                hash[int((float(j)/i)*100000)][1] = j;
                hash[int(float(j)/i*100000)][2] = i;
            }
    cout << "0/1" << endl; 
    for (i = 1; i <= 100000; i++)
        if (hash[i][2])
            cout << hash[i][1] << "/" << hash[i][2] << "\n";
    return 0;
}
