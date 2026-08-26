#include<bits/stdc++.h>
using namespace std;

pair<int, int> arr[10005];
float dis = 10000;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void conquer(int l, int r, int mid) {
    vector<pair<int, int>> tmp;
    for (int i = l; i <= r; i++) {
        if (dis > abs(arr[mid].first - arr[i].first)) tmp.push_back(arr[i]);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for (int i = 0; i < tmp.size(); i++) {
        for (int j = i + 1; j < tmp.size(); j++) {
            if (tmp[j].second - tmp[i].second > dis) break;
            float d = hypot(tmp[i].first - tmp[j].first, tmp[i].second - tmp[j].second);
            dis = min(dis, d);
        }
    }
}

void divide(int l, int r) {
    if (l >= r) return;
    if (abs(l - r) == 1) {
        dis = min(dis, (float) hypot(arr[l].first - arr[r].first, arr[l].second - arr[r].second));
        return;
    }
    int mid = (l + r) / 2;
    divide(l, mid);
    divide(mid + 1, r);
    conquer(l, r, mid);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
        sort(arr, arr + n);
        divide(0, n - 1);
        if (dis >= 10000) cout << "INFINITY" << '\n';
        else cout << dis << '\n';
        dis = 10000;
    }
    return 0;
}
