/*
ID:jake1994
LANG:C++
TASK:subset
*/
//����Ĥ�ݵĴ�ţ�� 
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int dp[10000], n, max;
int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    fin>>n;
    max=(n*(n+1))/2;
    if (max&1==1)//�ж��Ƿ�Ϊ���� 
    {
        fout<<0<<endl;
        return 0;
    }
    max/=2;
    dp[0]=1;
    for (int i=1;i<=n;i++)  //���ñ�����˼�룬�������ܹ��ճ�һ��ķ�������ע��Ҫ���� �������� 
        for (int j=max;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];    //dp[i]��ʾ�ܹ��ճ��ܺ�Ϊi�ķ�������Ȼ�����д���������һ�¼ӷ�ԭ�� 
    fout<<dp[max]/2<<endl;
    return 0;
}
