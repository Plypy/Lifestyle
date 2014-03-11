#include <stdio.h>
#include <string.h>
const int bas[7]={0,1,12,30,24,60,60};
const int birth[7]={0,1990,5,18,10,20,0};
int in[7],ans[7],t;

int main(){   
    scanf ("%d/%d/%d/%d/%d/%d",in+1,in+2,in+3,in+4,in+5,in+6);
    for (int i=1;i<7;i++)
    {
        if (in[i]==birth[i])
            continue;
        else 
        {
            t=in[i]-birth[i];
            break;
        }
    }
    for (int i=6;i>=1;i--)
    {
        if (t>0)
            ans[i]+=in[i]-birth[i];
        else 
            ans[i]+=birth[i]-in[i];
        if (ans[i]<0)
            ans[i]+=bas[i],ans[i-1]--;
    }
    printf ("%d",ans[1]);
    for (int i=2;i<=6;i++)
        printf ("/%d",ans[i]);
    return 0;
}
