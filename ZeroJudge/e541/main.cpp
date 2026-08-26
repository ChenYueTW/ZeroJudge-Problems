#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q, num = 1;
    while (cin >> n >> q) {
        if (n == 0 && q == 0) break;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (m[v[i]] == 0) {
                m[v[i]] = i + 1;
            }
        }
        cout << "CASE# " << num << ":" << '\n';
        for (int i = 0; i < q; i++) {
            int val; cin >> val;
            if (m[val] == 0) cout << val << " not found" << '\n';
            else cout << val << " found at " << m[val] << '\n';
        }
        num++;
    }
    return 0;
}
