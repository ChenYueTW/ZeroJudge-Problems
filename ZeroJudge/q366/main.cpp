#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];
pair<int, int> mov[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(n * m + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            arr[i][j] = val;
            v[val] = i * m + j + 1;
        }
    }

    for (int i = 0; i < q; i++) {
        int val;
        cin >> val;
        vector<int> ans;
        int s = v[val];
        int row = (v[val] - 1) / m, col = (v[val] - 1) % m;

        for (int j = 0; j < 4; j++) {
            int nrow = row + mov[j].first, ncol = col + mov[j].second;

            if (nrow < 0) nrow = n - 1;
            else if (nrow >= n) nrow = 0;

            if (ncol < 0) ncol = m - 1;
            else if (ncol >= m) ncol = 0;

            ans.push_back(arr[nrow][ncol]);
        }
        sort(ans.begin(), ans.end());

        for (int j : ans) cout << j << " ";
        cout << '\n';
    }
    return 0;
}
