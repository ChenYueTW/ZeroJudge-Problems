#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.end());
    int ans = 0, L = v[0].first, R = v[0].second;
    for (int i = 1; i < n; i++) {
        int a = v[i].first, b = v[i].second;

        if (R < a) {
            ans += R - L;
            L = a;
            R = b;
        } else if (R < b) {
            R = b;
        }
    }
    ans += R - L;

    cout << ans;
    return 0;
}
