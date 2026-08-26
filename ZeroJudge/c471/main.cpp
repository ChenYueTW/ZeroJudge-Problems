#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmb(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second < b.first * a.second;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        v[i] = make_pair(a[i], val);
    }
    sort(v.begin(), v.end(), cmb);
    ll num = v[0].first, ans = 0;
    for (int i = 1; i < n; i++) {
        ans += num * v[i].second;
        num += v[i].first;
    }
    cout << ans;
    return 0;
}
