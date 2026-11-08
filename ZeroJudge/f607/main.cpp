#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

vector<pii> c;
set<int> s;

bool cmp(pii a, pii b) {
    return a.second < b.second;
}

int main() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        c.push_back({a, b});
    }
    sort(c.begin(), c.end(), cmp);
    s.insert(0);
    s.insert(l);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int k = c[i].first;
        s.insert(k);
        auto ca = s.find(k);
        auto pre = prev(ca), nxt = next(ca);
        ans += *nxt - *pre;
    }
    cout << ans;
    return 0;
}