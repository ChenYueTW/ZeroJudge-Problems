#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    while (cin >> a >> b) {
        string ans;
        unordered_map<char, pair<int, int>> u;
        for (int i = 0; i < a.length(); i++) u[a[i]].first++;
        for (int i = 0; i < b.length(); i++) u[b[i]].second++;

        for (auto it = u.begin(); it != u.end(); it++) {
            pair<int, int> p = it -> second;
            if (p.first == 0 || p.second == 0) continue;
            for (int j = 0; j < min(p.first, p.second); j++) {
                ans += it -> first;
            }
        }
        sort(ans.begin(), ans.end());
        for (char c : ans) cout << c;
        cout << '\n';
    }
    return 0;
}
