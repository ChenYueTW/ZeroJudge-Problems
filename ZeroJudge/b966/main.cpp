#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    int L = v[0].first;
    int R = v[0].second;
    for (int i = 1; i < n; i++) {
        int a = v[i].first, b = v[i].second;

        if (a > R) {
            ans += R - L;
            L = a;
            R = b;
        } if (a <= R && b > R) {
            R = b;
        }
    }
    ans += R - L;

    cout << ans;

    return 0;
}
