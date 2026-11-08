#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

priority_queue<pii, vector<pii>, greater<pii>>q;
ll nxt[300005], sand[300005], pre[300005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        ll val; cin >> val;
        q.push({val, i});
        sand[i] = val;
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    for (int i = 1; i <= n; i++) {
        if (sand[i] == 0) {
            pre[nxt[i]] = pre[i];
            nxt[pre[i]] = nxt[i];
        }
    }
    ll ans = 0;
    while (!q.empty() && q.top().first <= t) {
        pii p = q.top();
        if (p.first == 0 || (p.first != sand[p.second])) {
            q.pop();
            continue;
        }
        ans += p.first;
        ll nxtIndex = nxt[p.second];

        pre[nxt[p.second]] = pre[p.second];
        nxt[pre[p.second]] = nxt[p.second];
        sand[p.second] = 0;
        if (nxtIndex == n + 1) { // last
            q.pop();
            continue;
        }
        q.pop();
        q.push({sand[nxtIndex] + p.first, nxtIndex});
        sand[nxtIndex] += p.first;
    }
    cout << ans;
    return 0;
}