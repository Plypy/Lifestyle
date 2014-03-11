#include <iostream>
using namespace std;
int main()
{
    int n,num[100]={0},buf[100]={0},*ptr=num;
    cin>>n;
    cin.get();
    while (cin.peek()!=EOF&&cin.peek()!='\n')
    {
        *ptr++=cin.get()-'0';	
        if (*(ptr-1)>10)
            *(ptr-1)-=7;
    }
    int size=int(ptr-num);
    for (int t=0;t<30;t++)
    {
        ptr=buf;
        for (int i=size-1;i>=0;i--)
            *ptr++=num[i];
        for (int i=0;i<=size;i++)
        {
            num[i]+=buf[i];
            if (num[i]>=n)
            {
                num[i]-=n;
                num[i+1]++;
            }
        }
        if (num[size]!=0)
            size++;
        bool flag=true;
        for (int i=0;i<size/2;i++)
            if (num[i]!=num[size-1-i])
            {
                flag=false;
                break;
            }
        if (flag)
        {
            cout<<t+1;
            exit(0);
        }
    }
    cout<<"Impossible";
    return 0;
}
