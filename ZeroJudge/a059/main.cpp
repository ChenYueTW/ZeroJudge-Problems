#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = sqrt(a); i <= sqrt(b); i++) {
        if (i < sqrt(a)) continue;
        ans += i * i;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}