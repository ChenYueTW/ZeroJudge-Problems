#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n;
    map<int, int> v;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (v[val] == 0) {
            v[val] = 1;
        } else {
            v[val] += 1;
        }
    }
    cin >> m;

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;

        cout << v[val] << '\n';
    }
    return 0;
}
