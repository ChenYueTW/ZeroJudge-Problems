#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmb(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) v[i] = {a, b};
        else v[i] = {b, a};
    }

    sort(v.begin(), v.end(), cmb);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a = v[i].first, b = v[i].second;

        if (a > b && a > 0) {
            ans += a;
        } else if (b > a && b > 0) {
            ans += b;
        }

        cout << ans << '\n';
    }
    return 0;
}
