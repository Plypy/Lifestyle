#include<iostream>
#include<cstring>
using namespace std;
string S,Temp[81][81],F[81];
int N;
bool cmp(string s1,string s2)
{
    string str1,str2;
    str1=s1;str2=s2;
    while (str1[0]=='0' && str1.size()>1)
        str1.erase(0,1);
    while (str2[0]=='0' && str2.size()>1)
        str2.erase(0,1);
    if (str1.size()<str2.size())
        return true;
    else if (str1.size()>str2.size())
        return false;
    for (int i=0;i<str1.size();i++)
        if (str1[i]>str2[i])
            return false;
        else if (str1[i]<str2[i])
            return true;
    return false;
}
void Init()
{
    cin>>S;
    N=S.size();
    S=' '+S;
    for (int d=1;d<=N;d++)
    {
        for (int i=1;i<=N-d+1;i++)
        {
            int j=i+d-1;
            Temp[i][j]=S.substr(i,d);
        }
        F[d]=Temp[1][d];
    }
}
void C_out()
{
    int i=1;
    while (i!=N-F[N].size()+1)
    {
        cout<<F[i]<<",";
        i+=F[i].size();
    }
    cout<<F[N]<<endl;
}
void Work()
{
    for (int i=2;i<=N;i++)
        for (int j=i;j>=1;j--)
            if (cmp(F[j-1],Temp[j][i]))
                if (cmp(Temp[j][i],F[i]))
                    F[i]=Temp[j][i];

    int len=N-F[N].size();
    F[N-F[N].size()+1]=F[N];
    for (int i=len;i>=1;i--)
    {
        F[i]="";
        for (int j=i;j<=len;j++)
            if (cmp(Temp[i][j],F[j+1]))
                if (cmp(F[i],Temp[i][j]))
                    F[i]=Temp[i][j];
    }
    C_out();
}
int main()
{
    Init();
    Work();
    return 0;
}
