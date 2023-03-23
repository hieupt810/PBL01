#include <iostream>
using namespace std;

void init()
{
    freopen("Input.inp", "r", stdin);
    freopen("Output.out", "w", stdout);
}

void quickSort(int a[], int l, int r)
{
    int i = l, j = r;
    int pivot = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] < pivot)
            ++i;
        while (a[j] > pivot)
            --j;
        if (i <= j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            ++i;
            --j;
        }
    }
    if (l < j)
        quickSort(a, l, j);
    if (i < r)
        quickSort(a, i, r);
}

long long d;
int a[100001], n, k, res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (d > 0 && ++res <= k)
    {
        quickSort(a, 1, n);
        d -= a[n];
        a[n] /= 2;
    }
    if (res <= k && d <= 0)
        cout << res;
    else
        cout << -1;
    return 0;
}