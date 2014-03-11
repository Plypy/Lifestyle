#include <iostream>
using namespace std;
int n, bound;
short tree[2<<11];
int build(int root)
{
    if (tree[root])
        return tree[root];
    int l = root << 1;
    int r = l+1;
    if (build(l) == build (r))
        return tree[root] = tree[l];
    else
        return tree[root] = 3;
}
void print(int root)
{
    int l = root << 1;
    int r = l+1;
    if (l <= bound)
    {
        print(l);
        print(r);
    }
    switch (tree[root])
    {
        case 1:
            printf("B");
            break;
        case 2:
            printf("I");
            break;
        case 3:
            printf("F");
            break;
    }
}
int main()//1:B  2:I 3:F
{
    int a;
    n = 1;
    cin >> a;
    n <<= a;
    bound = n<<1;
    char tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        tree[n+i] = tmp-'0'+1;
    }
    build(1);
    print(1);
    return 0;
}

