#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, r;
    cin >> n >> r;
    int ans = 1000;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ans = min(ans, v);
    }
    cout << ans * r * r << "π";
    return 0;
}
