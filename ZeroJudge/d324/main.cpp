#include <bits/stdc++.h>
using namespace std;

int tmp[9];
int a, b, soln = 1;

void dfs(int step) {
    if (step == a) {
        dfs(step + 1);
        return;
    }
    if (step == 9) {
        cout << " " << soln << "      ";
        for (int i = 1; i <= 8; i++) cout << tmp[i] << (i == 8 ? "" : " ");
        cout << '\n';
        soln++;
        return;
    }
    for (int col = 1; col <= 8; col++) {
        bool f = 0;
        if (b == col) continue;
        for (int j = 1; j <= 8; j++) {
            if (j == step || tmp[j] == 0) continue;
            if (tmp[j] == col) {f = 1; break;}
            if (abs(tmp[j] - col) == abs(step - j)) {f = 1; break;}
        }
        if (!f) {
            tmp[step] = col;
            dfs(step + 1);
            tmp[step] = 0;
        }
    }
}

void solve() {
    cin >> b >> a;
    memset(tmp, 0, sizeof(tmp));
    tmp[a] = b;
    soln = 1;
    cout << "SOLN       COLUMN" << '\n';
    cout << " #      1 2 3 4 5 6 7 8" << '\n' << '\n';
    dfs(1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        if (i > 0) cout << '\n';
        solve();
    }
    return 0;
}
