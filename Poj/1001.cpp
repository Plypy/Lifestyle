#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string mlp;     //乘数
    int power;     //乘数的幂
    int r[151];    //保存结果
    int hdot;
    while(cin>>mlp>>power)
    {
        hdot=0;
        for(int t=0;t<150;t++)
        {
            r[t]=-1;
        }
        if(mlp.find(".")!=string::npos)
            hdot=mlp.length()-mlp.find(".")-1;
        string::iterator itr=mlp.end()-1;
        while(hdot>0&&itr>=mlp.begin())
        {
            if(*itr!='0')
                break;
            hdot--;
            itr--;
        }
        int cn=0;
        while(itr>=mlp.begin())
        {
            if(*itr!='.')
            {
                r[cn]=*itr-'0';
                cn++;
            }
            itr--;
        }
        int k=cn-1;
        int m=0;     //保存临时数；
        while(k>-1)
        {
            m=m*10+r[k];
            k--;
        }
        for(int i=1;i<power;i++)
        {
            int j=0;
            while(r[j]>-1)
            {
                r[j]=r[j]*m;
                j++;
            }
            j=0;
            while(r[j]>-1)
            {
                if(r[j+1]==-1&&r[j]>=10)
                    r[j+1]=r[j]/10;
                else
                    r[j+1]+=r[j]/10;
                r[j]=r[j]%10;
                j++;
            }
        }
        hdot=hdot*power;
        int cnt=0;
        while(r[cnt]>-1)
            cnt++;
        if(hdot>=cnt)
        {
            cout<<".";
            while(hdot>cnt)
            {
                cout<<"0";
                hdot--;
            }
            hdot=0;
        }
        for(k=cnt-1;k>=0;k--)
        {
            if((k+1)==hdot&&hdot!=0)
                cout<<".";
            cout<<r[k];
        }
        cout<<endl;
    }
    return 0;
}
