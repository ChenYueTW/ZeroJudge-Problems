#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];
int n, m;
pair<int, int> mov[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool solve(int r, int c, int index) {
    for (int i = 0; i < 4; i++) {
        if ((index == 0 && i == 1) || (index == 1 && i == 0)) continue;
        if ((index == 2 && i == 3) || (index == 3 && i == 2)) continue;
        int nr = r + mov[i].first, nc = c + mov[i].second;

        if (!(nr >= 0 && nr < n && nc >= 0 && nc < m)) continue;
        if (arr[nr][nc] == -1 || arr[nr][nc] == 1) continue;

        if (arr[nr][nc] == 2) {
            return true;
        }
        arr[r][c] = 1;

        if (solve(nr, nc, i)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int sr, sc;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m;  j++) {
            char c = s[j];
            if (c == 'S') {
                arr[i][j] = 0;
                sr = i;
                sc = j;
            } else if (c == '.') arr[i][j] = 0;
            else if (c == 'T') arr[i][j] = 2;
            else arr[i][j] = -1;
        }
    }
    bool ans = solve(sr, sc, -1);
    if (!ans) cout << "wasted";
    else cout << "mission passed respect+";
    return 0;
}
