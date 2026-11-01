#include<bits/stdc++.h>
using namespace std;
#define ll long long

int h[2005][2005];
ll P[2005][2005];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> h[i][j];
    for (int i = 0; i <= n + 1; i++) 
        for (int j = 0; j <= n + 1; j++)
            P[i][j] = 0;

    bool f = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
            ll cur = h[i][j] - P[i][j];
            if (cur < 0) { f = 1; break;}
            if (cur > 0) {
                if (i + k - 1 > n || j + k - 1 > n) { f = 1; break; }
                P[i][j] += cur;
                P[i][j + k] -= cur;
                P[i + k][j] -= cur;
                P[i + k][j + k] += cur;
            }
        }
        if (f) break;
    }
    if (f) cout << "No";
    else cout << "Yes";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        if (i != t - 1) cout << '\n';
    }
    return 0;
}