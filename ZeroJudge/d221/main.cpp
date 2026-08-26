#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        priority_queue<ll, vector<ll>, greater<ll>> v;
        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            v.push(val);
        }

        ll cost = 0;
        for (int i = 0; i < n - 1; i++) {
            ll t1 = v.top();
            v.pop();
            ll t2 = v.top();
            v.pop();
            v.push(t1 + t2);
            cost += t1 + t2;
        }
        cout << cost << '\n';
    }
    return 0;
}
