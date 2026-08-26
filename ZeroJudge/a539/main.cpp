#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;

    while (cin >> n) {
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        bool f = true;
        while (f) {
            f = false;
            for (int i = 0; i < n - 1; i++) {
                if (v[i] > v[i + 1]) {
                    swap(v[i], v[i + 1]);
                    ans++;
                    f = true;
                }
            }
        }
        cout << "Minimum exchange operations : " << ans << '\n';
    }
}
