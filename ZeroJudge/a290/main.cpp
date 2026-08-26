#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;
bitset<10005> visited;

bool dfs(int a, int b) {
    visited[a] = 1;
    if (a == b) return true;

    bool found = 0;
    for (int i = 0; i < mp[a].size(); i++) {
        if(visited[mp[a][i]] == 0 && dfs(mp[a][i], b)) found = 1;
    }
    return found;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n) {
        mp.clear();
        visited.reset();
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            mp[a].push_back(b);
        }
        int a, b;
        cin >> a >> b;
        cout << (dfs(a, b) ? "Yes!!!" : "No!!!") << '\n';
    }
    return 0;
}
