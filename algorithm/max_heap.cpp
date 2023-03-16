#include <iostream>
#include <fstream>
using namespace std;

void init() {
    freopen("Input.inp", "r", stdin);
    freopen("Output.out", "w", stdout);
}

void max_heapify(int a[], int i, int n) {
    int left = 2 * i, right = 2 * i + 1, largest;
    if (left <= n && a[left] > a[i]) largest = left;
    else largest = i;
    if (right <= n && a[right] > a[largest]) largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        max_heapify(a, largest, n);
    }
    return;
}

void build_maxheap(int a[], int n) {
    for (int i = n/2; i >= 1; i--) max_heapify(a, i, n);
    return;
}

long long d;
int a[100001], n, k, res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    init();
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build_maxheap(a, n);
    while (d > 0 && ++res <= k + 1) {
        d -= a[1];
        a[1] /= 2;
        max_heapify(a, 1, n);
    }
    if (res <= k && d <= 0) cout << res;
    else cout << -1;
    return 0;
}