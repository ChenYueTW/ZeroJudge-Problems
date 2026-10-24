    #include<bits/stdc++.h>
    using namespace std;

    struct boom_count {
        int x;
        int y;
        int step;
    };

    int m, n, q, boomed = 1;
    int mp[505][505], visited[505][505];
    pair<int, int> nxt[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<boom_count> w;

    void bfs(int r, int sx, int sy) {
        w.push({sx, sy, r});
        visited[sx][sy] = r;

        while(!w.empty()) {
            int num = w.size();
            for (int i = 0; i < num; i++) {
                pair<int, int> p = {w.front().x, w.front().y};

                if (w.front().step == 0) {
                    w.pop();
                    continue;
                }
                for (int j = 0; j < 4; j++) {
                    int rx = p.first + nxt[j].first, ry = p.second + nxt[j].second;
                    if (rx < 0 || rx > m - 1 || ry < 0 || ry > n - 1) continue;
                    if (mp[rx][ry] == -1) continue;

                    int e = w.front().step - 1;
                    if (e > visited[rx][ry]) {
                        if (visited[rx][ry] == -1) boomed++;

                        if (mp[rx][ry] > e) e = mp[rx][ry];

                        w.push({rx, ry, e});
                        visited[rx][ry] = e;
                    }
                }
                w.pop();
            }
        }
    }

    int main() {
        cin.tie(0), ios::sync_with_stdio(0);
        cin >> m >> n >> q;
        int x, y;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == -2) {
                    x = i;
                    y = j;
                }
            }
        }
        int L = 0, R = m * n, ans = 0;
        while (R >= L) {
            memset(visited, -1, sizeof(visited));
            w = {};
            int mid = (L + R) / 2;
            bfs(mid, x, y);
            if (boomed >= q) {
                R = mid - 1;
                ans = mid;
            } else L = mid + 1;

            boomed = 1;
        }
        cout << ans;
        return 0;
    }