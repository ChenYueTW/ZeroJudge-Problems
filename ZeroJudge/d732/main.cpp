#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < k; i++) {
        int val; cin >> val;

        if (val < v.front() || val > v.back()) {
            cout << 0 << '\n';
            continue;
        }

        bool found = 0;
        int left = 0, right = n - 1;
        while (right >= left) {
            int mid = (left + right) / 2;
            if (v[mid] > val) right = mid - 1;
            else if (v[mid] < val) left = mid + 1;
            else {
                found = 1;
                cout << mid + 1 << '\n';
                break;
            }
        }
        if (!found) cout << 0 << '\n';
    }
    return 0;
}
