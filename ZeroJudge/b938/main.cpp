#include <bits/stdc++.h>
using namespace std;

bool b[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int num = n;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        if (k == num || b[k]) {
            cout << "0u0 ...... ?" << '\n';
            continue;
        }
        k++;
        while (k < num) {
            if (!b[k]) break;
            else k++;
        }
        b[k] = 1;
        cout << k << '\n';

        if (num == k) {
            while(num--) {
                if (!b[num]) {
                    break;
                }
            }
        }
    }

    return 0;
}
