#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sum[1000005];
unsigned ll sqsum[1000005];

long double solve(int l, int r) {
    if (l == r) return 0;
    long double a = sum[r] - sum[l - 1], b = sqsum[r] - sqsum[l - 1];

    a /= (r - l + 1);
    b /= (r - l + 1);

    return b - a * a;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    sum[0] = 0, sqsum[0] = 0;

    for (int i = 1; i <= n; i++) {
        ll v;
        cin >> v;
        sum[i] = v + sum[i - 1];
        sqsum[i] = v * v + sqsum[i - 1];
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        ll ans = round(solve(a, b));
        cout << ans << '\n';
    }
    return 0;
}
