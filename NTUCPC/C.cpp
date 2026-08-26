#include <bits/stdc++.h>
using namespace std;

int p[500005];
unordered_map<int, unordered_set<int>> mp;

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int val; cin >> val;
        mp[val].insert(i + 1);
    }
    cout << mp.size();
    for (int i = 0; i < q; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (s == "?") {
            cout << mp[a].size();
        } else {

        }
    }
}
