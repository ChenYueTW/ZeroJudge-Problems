#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < m; i++) p.push(0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = p.top();
        p.pop();
        ans = max(ans, val + v[i]);
        p.push(val + v[i]);
    }
    cout << ans;
    return 0;
}
