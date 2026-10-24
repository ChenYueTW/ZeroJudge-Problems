#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n, k;

bool bs(int d) {
    int cnt = 0, loc = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] - loc > d) {
            loc = v[i];
            cnt++;
        } 
        if (i == n - 1) cnt++;

        if (cnt > k) return false;
    }
    return true;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    int L = 0, R = (v.back() - v.front()), ans = 0;
    while (R >= L) {
        int mid = (L + R) / 2;
        if (bs(mid)) {R = mid - 1; ans = mid;}
        else L = mid + 1;
    }
    cout << ans;
    return 0;
}