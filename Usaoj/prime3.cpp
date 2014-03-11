/*
    ID : jake1994
    PROG : prime3
    LANG : C++
*/
#include<stdio.h>
#include<string.h>
int a[6][6],ss[100000],n,sum;
char ans[201][27];
int main()
{
    FILE *fi,*fo;
    fi=fopen("prime3.in","r");
    fo=fopen("prime3.out","w");
    int i,j,k,tmp;
    fscanf(fi,"%d%d",&n,&a[1][1]);
    ss[1]=1;
    for(i=2;i<=99999;i++)
    {
      if(ss[i]==1)continue;
      for(j=i*2;j<=99999;j+=i)ss[j]=1;
    }
    for(a[2][2]=0;a[2][2]<=9;a[2][2]++)
      for(a[3][3]=0;a[3][3]<=9;a[3][3]++)
        for(a[4][4]=0;a[4][4]<=9;a[4][4]++)
        {
          a[5][5]=n-a[4][4]-a[3][3]-a[2][2]-a[1][1];
          if(a[5][5]<0||a[5][5]>9)continue;
          if(a[5][5]%2==0)continue;
          tmp=a[1][1]*10000+a[2][2]*1000+a[3][3]*100+a[4][4]*10+a[5][5];
          if(ss[tmp]==1)continue;
          for(a[5][1]=1;a[5][1]<=9;a[5][1]+=2)
            for(a[4][2]=0;a[4][2]<=9;a[4][2]++)
              for(a[2][4]=0;a[2][4]<=9;a[2][4]++)
              {
                a[1][5]=n-a[5][1]-a[4][2]-a[3][3]-a[2][4];
                if(a[1][5]<0||a[1][5]>9)continue;
                if(a[1][5]%2==0)continue;
                tmp=a[5][1]*10000+a[4][2]*1000+a[3][3]*100+a[2][4]*10+a[1][5];
                if(ss[tmp]==1)continue;
                for(a[3][1]=1;a[3][1]<=9;a[3][1]++)
                  for(a[3][2]=0;a[3][2]<=9;a[3][2]++)
                    for(a[3][4]=0;a[3][4]<=9;a[3][4]++)
                    {
                      a[3][5]=n-a[3][1]-a[3][2]-a[3][3]-a[3][4];
                      if(a[3][5]<0||a[3][5]>9)continue;
                      if(a[3][5]%2==0)continue;
                      tmp=a[3][1]*10000+a[3][2]*1000+a[3][3]*100+a[3][4]*10+a[3][5];
                      if(ss[tmp]==1)continue;
                      for(a[2][1]=1;a[2][1]<=9;a[2][1]++)
                      {
                        a[4][1]=n-a[1][1]-a[2][1]-a[3][1]-a[5][1];
                        if(a[4][1]<=0||a[4][1]>9)continue;
                        tmp=a[1][1]*10000+a[2][1]*1000+a[3][1]*100+a[4][1]*10+a[5][1];
                        if(ss[tmp]==1)continue;
                        for(a[2][5]=1;a[2][5]<=9;a[2][5]+=2)
                        {
                          a[2][3]=n-a[2][1]-a[2][2]-a[2][4]-a[2][5];
                          if(a[2][3]<0||a[2][3]>9)continue;
                          tmp=a[2][1]*10000+a[2][2]*1000+a[2][3]*100+a[2][4]*10+a[2][5];
                          if(ss[tmp]==1)continue;
                          a[4][5]=n-a[1][5]-a[2][5]-a[3][5]-a[5][5];
                          if(a[4][5]<0||a[4][5]>9)continue;
                          if(a[4][5]%2==0)continue;
                          tmp=a[1][5]*10000+a[2][5]*1000+a[3][5]*100+a[4][5]*10+a[5][5];
                          if(ss[tmp]==1)continue;
                          a[4][3]=n-a[4][1]-a[4][2]-a[4][4]-a[4][5];
                          if(a[4][3]<0||a[4][3]>9)continue;
                          tmp=a[4][1]*10000+a[4][2]*1000+a[4][3]*100+a[4][4]*10+a[4][5];
                          if(ss[tmp]==1)continue;
                          for(a[5][2]=1;a[5][2]<=9;a[5][2]+=2)
                          {
                            a[1][2]=n-a[2][2]-a[3][2]-a[4][2]-a[5][2];
                            if(a[1][2]<=0||a[1][2]>9)continue;
                            tmp=a[1][2]*10000+a[2][2]*1000+a[3][2]*100+a[4][2]*10+a[5][2];
                            if(ss[tmp]==1)continue;
                            for(a[5][3]=1;a[5][3]<=9;a[5][3]+=2)
                            {
                              a[1][3]=n-a[2][3]-a[3][3]-a[4][3]-a[5][3];
                              if(a[1][3]<=0||a[1][3]>9)continue;
                              tmp=a[1][3]*10000+a[2][3]*1000+a[3][3]*100+a[4][3]*10+a[5][3];
                              if(ss[tmp]==1)continue;
                              a[1][4]=n-a[1][1]-a[1][2]-a[1][3]-a[1][5];
                              if(a[1][4]<=0||a[1][4]>9)continue;
                              tmp=a[1][1]*10000+a[1][2]*1000+a[1][3]*100+a[1][4]*10+a[1][5];
                              if(ss[tmp]==1)continue;
                              a[5][4]=n-a[1][4]-a[2][4]-a[3][4]-a[4][4];
                              if(a[5][4]<0||a[5][4]>9)continue;
                              if(a[5][4]%2==0)continue;
                              tmp=a[1][4]*10000+a[2][4]*1000+a[3][4]*100+a[4][4]*10+a[5][4];
                              if(ss[tmp]==1)continue;
                              tmp=a[5][1]*10000+a[5][2]*1000+a[5][3]*100+a[5][4]*10+a[5][5];
                              if(ss[tmp]==1)continue;
                              sum++;
                              for(i=1;i<=5;i++)for(j=1;j<=5;j++)ans[sum][i*5-6+j]=a[i][j]+'0';
                            }
                          }
                        }
                      }
                    }
              }
        }
    for(i=1;i<=sum-1;i++)
      for(j=i+1;j<=sum;j++)
        if(strcmp(ans[i],ans[j])>0)
        {
          strcpy(ans[0],ans[i]);
          strcpy(ans[i],ans[j]);
          strcpy(ans[j],ans[0]);
        }
    for(i=1;i<=sum;i++)
    {
      for(j=1;j<=5;j++)
      {
        for(k=1;k<=5;k++)fprintf(fo,"%c",ans[i][j*5-6+k]);
        fprintf(fo,"\n");
      }
      if(i!=sum)fprintf(fo,"\n");
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
