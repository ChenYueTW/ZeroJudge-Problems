#include<bits/stdc++.h>
using namespace std;

int mp[8][8], tmp[8];
int ans = 0;

// step: row
void dfs(int step) {
    if (step == 8) {
        int num = 0;
        for (int i = 0; i < 8; i++) {
            num += mp[i][tmp[i]];
        }
        ans = max(num, ans);
        return;
    }
    for (int i = 0; i < 8; i++) {
        bool f = 0;
        for (int j = 0; j < 8; j++) {
            if (tmp[j] == -1) continue;
            if (tmp[j] == i) {f = 1; break;}
            if (abs(j - step) == abs(tmp[j] - i)) {f = 1; break;}
        }
        if (!f) {
            tmp[step] = i;
            dfs(step + 1);
            tmp[step] = -1;
        }
    }
}

void solve() {
    memset(tmp, -1, sizeof(tmp));
    ans = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> mp[i][j];

    dfs(0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
