#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[300005];
int ans = 0, p = 0;
ll sum[300005];
vector<pair<int, int>> sorted;

void binary(int L, int R) {
    if (L == R) {
        ans = a[L];
        return;
    }
    if (L < R) {
        // find m
        while (sorted[p].second < L || sorted[p].second > R) p++;
        int m = sorted[p].second;
        ll left = sum[m - 1] - sum[L - 1];
        ll right = sum[R] - sum[m];
        if (left > right) binary(L, m - 1);
        else binary(m + 1, R);
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n; cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] += a[i] + sum[i - 1];
        sorted.push_back({a[i], i});
    }
    sort(sorted.begin(), sorted.end(), cmp);
    binary(1, n);
    cout << ans;
    return 0;
}