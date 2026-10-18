#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c, 0)), b(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            cin >> a[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> b[i][j];

    int ans = 0, cache_1 = 0, cache_2 = 0;
    // 0 and 360
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == b[i][j]) cache_1++;
            if (a[i][j] == b[r - i - 1][c - j - 1]) cache_2++;
        }
    }
    ans = max(ans, max(cache_1, cache_2));
    cache_1 = 0, cache_2 = 0;
    // 90 and 270
    if (r == c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < r; j++) {
                if (a[i][j] == b[r - j - 1][i]) cache_1++;
                if (a[i][j] == b[j][r - i - 1]) cache_2++;
            }
        }
    }
    ans = max(ans, max(cache_1, cache_2));
    ans *= 100;
    cout << ans / (r * c) << "%";
    return 0;
}