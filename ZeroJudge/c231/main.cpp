#include <bits/stdc++.h>
using namespace std;

int arr[10005][10005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    // r,c
    vector<pair<int, int>> v(c);
    int ans = c;

    for (int i = 0; i < c; i++) {
        int rr, cc;
        cin >> rr >> cc;
        v[i] = {rr, cc};

        for (int j = 0; j < i; j++) {
            float dis = sqrt(pow(v[j].first - v[i].first, 2) + pow(v[j].second - v[i].second, 2));
            if (dis < 3) {
                ans--;
                break;
            }
        }
    }
    if (ans == 0) ans = 1;

    cout << ans;
    return 0;
}
