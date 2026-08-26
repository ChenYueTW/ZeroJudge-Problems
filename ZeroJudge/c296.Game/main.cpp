#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = n - k + 1; i <= n; i++) ans = (ans + m) % i;
    cout << ans + 1;
    return 0;
}
