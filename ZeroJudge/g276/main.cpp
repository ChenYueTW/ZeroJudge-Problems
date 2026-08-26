#include <bits/stdc++.h>
using namespace std;

int arr[105][105];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    // r, c
    vector<pair<int, int>> v(k), pos(k);

    for (int i = 0; i < k; i++) {
        int r, c, s, t;
        cin >> r >> c >> s >> t;
        pos[i].first = r;
        pos[i].second = c;
        v[i].first = s;
        v[i].second = t;
    }

    int ans = 0;
    while (!pos.empty()) {
        // put bone
        for (int i = 0; i < pos.size(); i++) {
            int r = pos[i].first, c = pos[i].second;

            if (arr[r][c] == 0) {
                arr[r][c] = 1;
                ans+=1;
            }
        }

        set<pair<int, int>> wait;

        for (int i = 0; i < pos.size(); i++) {
            int r = pos[i].first + v[i].first;
            int c = pos[i].second + v[i].second;

            if (r < 0 || r >= n || c < 0 || c >= m) {
                pos.erase(pos.begin() + i);
                v.erase(v.begin() + i);
                i--;
                continue;
            }
            if (arr[r][c] == 1) {
                wait.insert({r, c});
                pos.erase(pos.begin() + i);
                v.erase(v.begin() + i);
                i--;
            } else {
                pos[i].first = r;
                pos[i].second = c;
            }

        }
        for (auto it : wait) {
            if (arr[it.first][it.second] == 1) {
                ans -= arr[it.first][it.second];
                arr[it.first][it.second] = 0;

            }
        }
    }
    cout << ans;

    return 0;
}
