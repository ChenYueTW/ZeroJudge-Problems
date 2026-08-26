#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p[35], tp[35];

ll dfs(ll a, ll b, ll t) {
    if (t == 0) return b;
    if (t == 1 && a == 1 && b == 2) return 3;
    if (t == 1 && a == 1 && b == 1) return 2;

    if (b <= p[t] / 2) {
        return dfs(a, b, t - 1) * 2;
    } else {
        return tp[t - 1] * 2 + dfs(1, b - p[t] / 2, t - 1);
    }
}

void solve() {
    ll k, a, b;
    cin >> k >> a >> b;
    cout << dfs(1, b, k) - dfs(1, a - 1, k);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    p[0] = 1; tp[0] = 1;
    for (int i = 0; i < 30; i++) {
        p[i + 1] = p[i] * 2;
        tp[i + 1] = tp[i] * 3;
    }
    for (int i = 0; i < T; i++) {
        cout << "Case " << i + 1 << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
