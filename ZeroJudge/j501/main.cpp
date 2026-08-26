#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n) {
        map<int, queue<int>> m;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            int val; cin >> val;
            m[val].push(i + 1);
        }

        for (int i = 0; i < n; i++) {
            int e = v[i];
            if (m.find(e) != m.end()) {
                cout << m[e].front() << " ";
                m[e].pop();
            }
        }
        cout << '\n';
    }
    return 0;
}
