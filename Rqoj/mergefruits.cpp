#include <iostream>
using namespace std;
const int MAXN = 10001;
int heap[MAXN];
int n;
void heapfy(int i)
{
    int l = i << 1;
    int r = (i << 1)+1;
    int min = i;
    if (l <= heap[0] && heap[min] > heap[l])
        min = l;
    if (r <= heap[0] && heap[min] > heap[r])
        min = r;
    if (min != i)
    {
        swap(heap[i],heap[min]);
        heapfy(min);
    }
}
int extract()
{
    int res = heap[1];
    swap(heap[1], heap[heap[0]--]);
    heapfy(1);
    return res;
}
void insert(int a)
{
    heap[++heap[0]]=a;
    int i = heap[0];
    while (i > 1 && heap[i] < heap[i>>1])
        swap(heap[i],heap[i>>=1]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> heap[i];
    heap[0] = n;
    for (int i = (n >> 1); i >= 1; i--)
        heapfy(i);
    int ans = 0;
    int a, b;
    while (heap[0] > 1)
    {
        a = extract();
        b = extract();
        insert(a+b);
        ans += a+b;
    }
    cout << ans;
    return 0;
}
