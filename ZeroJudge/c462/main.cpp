#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k;
    string s;
    cin >> k >> s;
    vector<int> v;
    v.push_back(1);

    bool isup = (s[0] < 'a');
    for (int i = 1; i < s.size(); i++) {
        if ((isup && s[i] < 'a') || (!isup && s[i] >= 'a')) {
            v[v.size() - 1]++;
        } else {
            v.push_back(1);
        }
        isup = (s[i] < 'a');
    }

    int ans = 0, t = 0;
    bool start = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == k) {
            if (!start) start = 1;
            t++;
        } else if (v[i] > k) {
            if (!start) {
                start = 1;
                t++;
            } else {
                ans = max(ans, k * (t + 1));
                start = 1;
                t = 1;
            }
        } else {
            if (start) {
                start = 0;
                ans = max(ans, k * t);
            }
            t = 0;
        }

        if (i == v.size() - 1 && start) {
            ans = max(ans, k * t);
        }
    }

    cout << ans << '\n';
    return 0;
}
