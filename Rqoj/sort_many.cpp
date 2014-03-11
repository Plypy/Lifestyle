// mergesort.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// mergesort
const int Big = 1000000;
void merge(int A[], int p, int q, int r)
{
    int n1, n2;
    n1 = q-p+1;
    n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for (int i = 0; i < n1; i++)
        L[i] = A[p+i];
    for (int i = 0; i < n2; i++)
        R[i] = A[q+i+1];
    L[n1] = R[n2] = Big;
    int i = 0, j = 0;
    for (int k = p; k < r+1; k++)
    {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}
void mergesort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p+r)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
}
// mergesort end
// bubblesort  begin huhuhhhhh...
void exchange(int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void bubblesort(int A[], int size)
{
    for (int i = 1; i < size; i++)
        for (int j = i+1; j <= size; j++)
            if (A[i] > A[j])
                exchange(A[i], A[j]);
}
// bubblesort end
// countingsort begin
void countingsort(int A[], int r)
{
    long tmp[r+1];
    for (int i = 0; i <= r; i++)
        tmp[i] = 0;
    for (int i = 1; i <= r; i++)
        tmp[A[i]]++;
    for (int i = 1; i <= r; i++)
        tmp[i] += tmp[i-1];
    int B[r+1];
    for (int i = 1; i <= r; i++)
    {
        B[tmp[A[i]]] = A[i];
        tmp[A[i]]--;
    }
    for (int i = 1; i <= r; i++)
        A[i] = B[i];
}
//countingsort end
// heapsort begin !!!!!!!!!!!!! by Ply_py!!!!!!!!!!!!!
inline int left(int i){return i<<1;}
inline int right(int i){return (i<<1)+1;}
inline int parent(int i){return i>>1;}
void heapfy(int *A, int i)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if (l<=A[0] && A[l]>A[i])
        largest = l;
    else
        largest = i;
    if (r<=A[0] && A[r]>A[largest])
        largest = r;
    if (largest!=i)
    {
        exchange(A[i], A[largest]);
        heapfy(A, largest);
    }
}
void buildheap(int *A, int len)
{
    A[0] = len;
    len >>= 1;
    for (int i = len; i >= 1; i--)
        heapfy(A, i);
}
void heapsort(int *A, int len)
{
    buildheap(A,len);
    for (int i = A[0]; i >= 2; i--)
    {
        exchange(A[1], A[i]);
        A[0]--;
        heapfy(A, 1);
    }
}
// heapsort end
// quicksort begin
int pa(int A[], int p, int r);
void quicksort(int A[], int p , int r);
void quicksort(int A[], int p, int r)
{
    if (p < r)
    {
        int q;
        q = pa(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}
int pa(int A[], int p, int r)
{
    int tmp = p+int(rand())%(r-p+1);
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r; j++)
        if (A[j] < x)
            exchange(A[++i], A[j]);
    exchange(A[i+1], A[r]);
    return i+1;
}
// quicksort end
// qsort cmp begin
int cmp(const void *p1, const void *p2)
{
    if (*(const int *)p1 < *(const int*)p2)
        return -1;
    return 1;
}
// qsort cmp end
int main()
{
    srand(time(0));
    time_t start, end;
    const int max = 100000;
    int array[max+1];
    for (int i = max; i >= 1; i--)
        array[i] = rand();
    int i;
    /*for (i = 1; i <= max; i++)
    {
        cout << array[i] << " ";
        if (i % 5 == 0)
            cout << endl;
    }
    if (i % 5 != 1)
        cout << endl;*/
    start = clock();
    //qsort(array+1,max,sizeof(int),cmp);
    //heapsort(array,max);
    //countingsort(array,max);
    //quicksort(array,1,max);
    //mergesort(array,1,max);
    end = clock();
    cout << (end-start)*1.0/CLOCKS_PER_SEC*1000 << "ms";
    cin.get();
    for (i = 1; i <= max; i++)
    {
        cout << array[i] << " ";
        if (i % 5 == 0)
            cout << endl;
    }
    if (i % 5 != 1)
        cout << endl;
    cin.get();
    return 0;
}
