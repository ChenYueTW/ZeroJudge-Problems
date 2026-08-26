#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<int, int> p;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool pcmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int maxx = -1000005, miny = 1000005;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        maxx = max(maxx, v[i].first);
        miny = min(miny, v[i].second);
    }
    p = *min_element(v.begin(), v.end(), pcmp);
    sort(v.begin(), v.end(), cmp);
    v.push_back({maxx + 10, miny - 10});
    v.push_back({p.first, miny - 10});

    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}
