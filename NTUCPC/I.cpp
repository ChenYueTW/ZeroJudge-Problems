#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;
int a[500005];
int m;

bool dfs(int v, int depth) {
    if (depth == m) return true;

    for (int k = 0; k < mp[v].size(); k++) { // uk = mp[v][k]
        bool f = 0;
        for (int j = 1; j <= m; j++) {
            if (a[j] <= mp[v].size()) {
                //cout << v << " " << a[j] << '\n';
                //cout << mp[v][a[j] - 1] << '\n';
                if (mp[v][a[j] - 1] == mp[v][k]) continue;
                if (a[j] >= mp[v].size() - 1) continue;
                cout << v << " " << a[jh] << '\n';
                cout << mp[v][a[j] - 1] << '\n';
                if (dfs(mp[v][a[j] - 1], depth + 1)) return true;
            }
        }
        //if (!f) cout << 0;
    }
    return false;
}

int main() {
    int n;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int val; cin >> val;
        mp[val].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (dfs(i, 0)) cout << 1;
        else cout << 0;
    }
    return 0;
}
