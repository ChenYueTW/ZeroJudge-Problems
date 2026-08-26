#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
    if (a.second == b.second) {
        int ca = a.first, cb = b.first;
        return ca < cb;
    }
    return a.second > b.second;
}

void solve() {
    string s;
    getline(cin, s);
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        if (!isalpha(s[i])) continue;
        m[tolower(s[i])]++;
    }
    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    int num = v[0].second;

    for (int i = 0; i < v.size(); i++) {
        if (v[i].second != num) break;
        cout << v[i].first;
    }
    cout << '\n';
}

int main() {
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}
