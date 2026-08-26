#include <bits/stdc++.h>
using namespace std;

int mp[105][105];
int n, m, record = 1, ans = 0;
pair<int, int> pre[105][105];
queue<pair<int, int>> q;
pair<int, int> nxt[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    pre[x][y] = {x, y};
    while (q.front().first != n - 1 || q.front().second != m - 1) {
        if (record == 0) return;
        pair<int, int> orin = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> to = {orin.first + nxt[i].first, orin.second + nxt[i].second};
            if (to.first < 0 || to.first > n - 1 || to.second < 0 || to.second > m - 1) continue;
            if (pre[to.first][to.second].first != -1) continue;
            if (mp[to.first][to.second] == 1) continue;
            record++;
            q.push(to);
            pre[to.first][to.second] = {orin.first, orin.second};
        }
        record--;
    }
}

void print(int x, int y) {
    if (x != 0 || y != 0) {
        ans++;
        cout << pre[x][y].first << " " << pre[x][y].second << '\n';
        print(pre[x][y].first, pre[x][y].second);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    memset(pre, -1, sizeof(pre));
    bfs(0, 0);

    if (record != 0)
        print(n - 1, m - 1);
    else
        cout << "No path found";

    cout << ans;
    return 0;
}
