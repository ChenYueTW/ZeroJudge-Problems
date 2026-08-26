#include <bits/stdc++.h>
using namespace std;

int n, a = 0;
int mp[105][105];
bool found = 0;
bool visited[105][105];
pair<int, int> nxt[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> pre[105][105];
queue<pair<int, int>> ans;

void bfs(int x, int y) {
    ans.push({x, y});
    visited[x][y] = 1;

    while (!ans.empty()) {
        pair<int, int> from = ans.front();
        for (int i = 0; i < 4; i++) {
            int rx = from.first + nxt[i].first, ry = from.second + nxt[i].second;
            if (rx < 0 || rx > n - 1 || ry < 0 || ry > n - 1) continue;
            if (visited[rx][ry] == 1 || mp[rx][ry] == 1) continue;
            pre[rx][ry] = {from.first, from.second};
            if (rx == n - 2 && ry == n - 2) {
                while (!ans.empty()) ans.pop();
                found = 1;
                break;
            }
            pre[rx][ry] = {from.first, from.second};
            ans.push({rx, ry});
            visited[rx][ry] = 1;
        }
        if(!ans.empty()) ans.pop();
        if (found) break;
    }
}

void print(int x, int y) {
    if (x == 1 && y == 1) return;
    print(pre[x][y].first, pre[x][y].second);
    a++;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            mp[i][j] = (s[j] == '#' ? 1 : 0);
        }
    }

    bfs(1, 1);
    if (found == 0) cout << "No solution!";
    else {
        print(n - 2, n - 2);
        cout << a + 1;
    }

    return 0;
}
