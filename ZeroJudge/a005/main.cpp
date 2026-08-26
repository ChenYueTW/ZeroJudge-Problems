#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> v(4);
        for (int j = 0; j < 4; j++) {
            int val;
            cin >> val;
            v[j] = val;
            cout << val << " ";
        }

        int d = v[1] - v[0];
        bool f = 1;
        for (int j = 1; j < 3; j++) {
            if (v[j + 1] - v[j] != d) {
                f = 0;
                break;
            }
        }

        if (f) cout << v[3] + d;
        else cout << v[3] * (v[3] / v[2]);
        cout << '\n';
    }
    return 0;
}
