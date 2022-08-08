#include <bits/stdc++.h>
using namespace std;

void init() {
    freopen("Input.inp", "r", stdin);
    freopen("Output.out", "w", stdout);
}

priority_queue<int> q;
long long d;
int n, k, res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    init();
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    while (d > 0 && ++res <= k + 1) {
        int x = q.top();
        d -= x;
        q.pop();
        q.push(x / 2);
    }
    if (res <= k && d <= 0) cout << res;
    else cout << -1;
    return 0;
}