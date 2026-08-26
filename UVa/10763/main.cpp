#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        unordered_map<int, int> v;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[a]--;
            v[b]++;
        }
        bool f = 0;
        for (auto& [loc, cnt] : v) {
            if (cnt != 0) {
                f = 1;
                break;
            }
        }
        cout << (f ? "NO" : "YES") << '\n';
    }
    return 0;
}
