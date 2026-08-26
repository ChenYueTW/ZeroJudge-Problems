#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        priority_queue<int> q;
        vector<pair<int, int>> p(n);

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            p[i] = make_pair(a, b);
        }
        sort(p.begin(), p.end());

        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            q.push(p[i].second);
            if (q.size() > k) q.pop();
            if (q.size() == k) {
                ans = min (ans, q.top() + p[i].first);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
