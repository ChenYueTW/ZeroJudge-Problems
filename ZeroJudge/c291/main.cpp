#include <bits/stdc++.h>
using namespace std;

bitset<50005> visited;
int v[50005];

void sear(int i) {
    if (visited[i]) return;
    visited[i] = 1;
    sear(v[i]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            sear(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}
