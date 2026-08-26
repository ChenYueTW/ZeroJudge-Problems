#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> dp(n + 1), l(n + 2);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        l[a] = b;
    }
    dp[1] = 1;

    for (int i = 1; i < n; i++) {
        ll x = dp[i];
        for (int j = 1; j <= 6; j++) {
            int to = min(i + j, n);
            if (l[to] != 0) {
                to = l[to];
            }
            dp[to] = (dp[to] + dp[i]) % 998244353;
        }
    }

    cout << dp[n];
    return 0;
}
