#include <bits/stdc++.h>
using namespace std;


int getDis(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    int d = 200000000;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[val] = {i + 1, 0};
    }
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[val].second = i + 1;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && j <= i; j++) {
            d = min(d, getDis(v[i], v[j]));
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (v[j].first - v[i].first > d) break;

            int dis = getDis(v[i], v[j]);

            if (dis < d) {
                d = dis;
                cnt = 1;
            } else if (dis == d) {
                cnt+=1;
            }
        }
    }

    cout << d << " " << cnt;
    return 0;
}
