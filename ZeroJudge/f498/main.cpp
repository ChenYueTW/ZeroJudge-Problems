#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while(cin >> n) {
        vector<int> m;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            m.push_back(val);
            v.push_back(val);

            int last = m.size() - 1;
            while (last > 0 && !m.empty()) {
                if (m[last] < m[(last - 1) / 2]) {
                    swap(m[last], m[(last - 1) / 2]);
                    last = (last - 1) / 2;
                } else {
                    break;
                }
            }
            last = v.size() - 1;
            while (last > 0 && !v.empty()) {
                if (v[last] > v[(last - 1) / 2]) {
                    swap(v[last], v[(last - 1) / 2]);
                    last = (last - 1) / 2;
                } else {
                    break;
                }
            }
        }
        for (int i : m) cout << i << " ";
        cout << '\n';
        for (int i : v) cout << i << " ";
        cout << '\n';
    }
    return 0;
}
