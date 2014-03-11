#include <stdio.h>
#define MAXN 10010
#define ORDLEN 20
char pat[MAXN], ans[MAXN];
char ord[ORDLEN], type[ORDLEN];
int t, n;
int ct;
void inorder(int pos)
{
    int lson = pos<<1;
    int rson = lson+1;
    if (lson <= n)
        inorder(lson);
    ans[++ct] = pat[pos];
    if (rson <= n)
        inorder(rson);
}
void preorder(int pos)
{
    int lson = pos<<1;
    int rson = lson+1;
    ans[++ct] = pat[pos];
    if (lson <= n)
        preorder(lson);
    if (rson <= n)
        preorder(rson);
}
void postorder(int pos)
{
    int lson = pos<<1;
    int rson = lson+1;
    if (lson <= n)
        postorder(lson);
    if (rson <= n)
        postorder(rson);
    ans[++ct] = pat[pos];
}
void deinorder(int pos)
{
    int lson = pos<<1;
    int rson = lson+1;
    if (lson <= n)
        deinorder(lson);
    ans[pos] = pat[++ct];
    if (rson <= n)
        deinorder(rson);
}
void depreorder(int pos)
{
    int lson = pos<<1;
    int rson = lson+1;
    ans[pos] = pat[++ct];
    if (lson <= n)
        depreorder(lson);
    if (rson <= n)
        depreorder(rson);
}
void depostorder(int pos)
{
    int lson = pos<<1;
    int rson = lson+1;
    if (lson <= n)
        depostorder(lson);
    if (rson <= n)
        depostorder(rson);
    ans[pos] = pat[++ct];
}
int main()
{
    scanf("%d", &t);
    for (; t; --t)
    {
        scanf("%d%s%s%s", &n, ord, type, pat+1);
        ct = 0;
        if (*type == 'E')
        {
            if (*ord == 'I')
                inorder(1);
            else if (ord[1] == 'R')
                preorder(1);
            else
                postorder(1);
        }
        else
        {
            if (*ord == 'I')
                deinorder(1);
            else if (ord[1] == 'R')
                depreorder(1);
            else
                depostorder(1);
        }
        ans[n+1] = 0;
        printf("Order #%d\n", t-1);
        printf("%s\n", ans+1);
    }
    return 0;
}
