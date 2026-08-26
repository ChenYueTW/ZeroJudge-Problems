#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < q; i++) {
        int val; cin >> val;

        bool found = 0;
        int left = 0, right = n - 1;
        while (right >= left) {
            int mid = (left + right) / 2;
            if (v[mid] > val) right = mid - 1;
            else if (v[mid] < val) left = mid + 1;
            else {
                found = 1;
                cout << "Yes" << '\n';
                break;
            }
        }
        if (!found) cout << "No" << '\n';
    }
    return 0;
}
