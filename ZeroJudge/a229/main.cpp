#include<bits/stdc++.h>
using namespace std;

int n, a = 0, b = 0;
int mp[30];

void dfs(int step) {
    if (step == 2 * n) {
        for (int i = 0; i < n * 2; i++) {
            if (mp[i] == 0) cout << "(";
            else cout << ")";
        }
        cout << '\n';
    }
    for (int i = 0; i < 2; i++) {
        if (a == n && i == 0) continue;
        else if ((b == n && i == 1) || (a == b && i == 1)) continue;
        if (i == 0) a++;
        else b++;
        mp[step] = i;
        dfs(step + 1);
        if (i == 0) a--;
        else b--;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n) {
        a = 1, b = 0;
        mp[0] = 0;
        dfs(1);
        cout << '\n';
    }
    return 0;
}