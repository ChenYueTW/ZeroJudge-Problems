#include <bits/stdc++.h>
using namespace std;

int ex, ey, T, sx, sy, ans = 0;
bool found = 0;
int mp[10][17];
bool visited[10][17];
pair<int, int> nxt[] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> pre[10][17];
queue<pair<int, int>> q;

queue<pair<int, int>> fire;
int firemp[10][17];

void bfs(int x, int y) {
    if (firemp[x][y] != 0 && firemp[x][y] <= T) return;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        int siz = q.size();
        for (int i = 0; i < siz; i++) {
            pair<int, int> from = {q.front().first, q.front().second};
            q.pop();
            for (int i = 0; i < 4; i++) {
                int rx = from.first + nxt[i].first, ry = from.second + nxt[i].second;
                if (rx < 0 || rx > 9 || ry < 0 || ry > 16) continue;
                if (mp[rx][ry] == 0 || visited[rx][ry] == 1) continue;
                if (firemp[rx][ry] != 0 && firemp[rx][ry] <= T + 1) continue;
                q.push({rx, ry});
                visited[rx][ry] = 1;
                pre[rx][ry] = {from.first, from.second};

                if (rx == ex && ry == ey) {
                    found = 1;
                    return;
                }
            }
        }
        T++;
    }
}

void update(int time) {
    int siz = fire.size();
    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < 4; j++) {
            int rx = fire.front().first + nxt[j].first, ry = fire.front().second + nxt[j].second;
            if (rx < 0 || rx > 9 || ry < 0 || ry > 16) continue;
            if ((rx == ex && ry == ey) || firemp[rx][ry] != 0 || mp[rx][ry] == 0) continue;
            fire.push({rx, ry});
            firemp[rx][ry] = time;
        }
        fire.pop();
    }
}

void print(int x, int y) {
    if (x == sx && y == sy) return;
    print(pre[x][y].first, pre[x][y].second);
    ans++;
}

string mapstr[] = {
"*****************",
"*...*.......**..*",
"**..*....*.*.*..*",
"*......*.**.**.**",
"*..**...**..**.**",
"**.....**..*.*..*",
"*....*..........*",
"*.....****.*...**",
"****.*.*........*",
"*****************",
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int fx, fy, firetime = 1;
    cin >> fx >> fy >> T >> sx >> sy >> ex >> ey;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 17; j++) {
            mp[i][j] = (mapstr[i][j] == '*' ? 0 : 1); // 0 can't move
        }
    }
    fire.push({fx, fy});
    firemp[fx][fy] = 1;
    while(!fire.empty()) {
        firetime++;
        update(firetime);
    }

    bfs(sx, sy);
    if (found) {
        print(ex, ey);
        cout << ans;
    } else {
        cout << "Help!";
    }
    return 0;
}
