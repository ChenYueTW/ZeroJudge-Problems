#include <bits/stdc++.h>
using namespace std;

int mp[105][105];
int n, m, ans = 0;
bool found = 0;
bool visited[105][105];
stack<pair<int, int>> s;
pair<int, int> nxt[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y) {
    s.push({x, y});
    visited[x][y] = 1;

    if (x != n - 1 || y != m - 1) {
        for (int i = 0; i < 4; i++) {
            int rx = x + nxt[i].first, ry = y + nxt[i].second;
            if (rx < 0 || rx > n - 1 || ry < 0 || ry > m - 1) continue;
            if (mp[rx][ry] == 1 || visited[rx][ry] == 1) continue;
            dfs(rx, ry);
            s.pop();
        }
    } else {
        found = 1;
        ans++;
    }
    visited[x][y] = 0;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];

    dfs(0, 0);
    cout << ans;
    return 0;
}
