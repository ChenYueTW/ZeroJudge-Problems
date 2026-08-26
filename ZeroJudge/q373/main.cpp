#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int v = 0;
    ll ans = 0, n;
    cin >> n;
    vector<ll> vec;

    for (int i = 0; i < n; i++) {
        int nv;
        cin >> nv;
        if (v == nv) {
            vec[vec.size() - 1]++;
        } else {
            vec.push_back(1);
            v = nv;
        }
    }
    for (ll i : vec) ans += i * (i + 1) / 2;

    cout << n * (n + 1) / 2 - ans << " " << ans << " " << 0;
    return 0;
}
