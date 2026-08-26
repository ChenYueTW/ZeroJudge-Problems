#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int first;
    while (cin >> first) {
        vector<int> v(7);
        int ans = 0;
        v[1] = first;
        for (int i = 2; i <= 6; i++) cin >> v[i];
        ans += v.back();
        // 5x5
        ans += v[5];
        if (v[5] * 11 <= v[1]) {
            v[1] -= v[5] * 11;
        } else {
            v[1] = 0;
        }
        // 4x4
        ans += v[4];
        bool f = 0;
        while (v[4] != 0) {
            if (v[2] >= 5) {
                v[2] -= 5;
                v[4]--;
            } else {
                if (v[1] >= (5 - v[2]) * 4) {
                    v[1] -= (5 - v[2]) * 4;
                    v[2] = 0;
                    v[4]--;
                } else {
                    v[2] = 0;
                    v[1] = 0;
                    break;
                }
            }
        }
        // 3x3
        ans += v[3] / 4;
        v[3] %= 4;
        if (v[3] != 0) {
            ans++;
            int leftover, maxCap2;
            if (v[3] == 1) {leftover = 27; maxCap2 = 5;}
            else if (v[3] == 2) {leftover = 18; maxCap2 = 3;}
            else {leftover = 9; maxCap2 = 1;}
            int k = min(v[2], maxCap2);
            v[2] -= k;
            int cap1 = leftover - 4 * k;
            v[1] -= min(v[1], cap1);
        }

        // 2x2
        if (v[2] != 0) {
            ans += v[2] / 9;
            v[2] %= 9;
            if (v[2] != 0) {
                ans++;
                int cap1 = 36 - 4 * v[2];
                v[1] -= min(v[1], cap1);
            }
        }
        // 1x1
        if (v[1] > 0) {
            ans += v[1] / 36;
            if (v[1] % 36 != 0) ans++;
        }
        if (ans != 0) cout << ans << '\n';
    }
    return 0;
}
