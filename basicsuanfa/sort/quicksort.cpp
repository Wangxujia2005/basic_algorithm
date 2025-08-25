#include <iostream>
using namespace std;

//分治
/*
确定分界点：q[l] q[(l+r)/2] q[r] 随机一个数
调整区间：
左边所有的数小于等于x
右边所有的数大于等于x
递归处理左右两段区间
*/

const int N = 1e6+10;

int n;
int q[N];

void quicksort(int q[], int l, int r)
{
    if (l >= r) return;
    int x = q[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (q[i] < x) i++;
        while (q[j] > x) j--;
        if (i <= j) swap(q[i++], q[j--]);
    }   
    quicksort(q, l, j);
    quicksort(q, i, r);
}

/*另一种方式
    int x = q[(l + r) / 2];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j + 1, r);
*/
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quicksort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}