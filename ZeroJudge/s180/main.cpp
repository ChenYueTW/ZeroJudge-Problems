#include<bits/stdc++.h>
using namespace std;

vector<int> t;
long long ans = 0;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        t.push_back(val);
    }
    sort(t.begin(), t.end());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a > t.back() || b < t.front()) continue;

        int l = 0, r = n - 1;
        int start = 0, end = 0;
        while (r >= l) {
            int mid = (l + r) / 2;
            
            if (t[mid] >= a) {
                start = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        l = 0, r = n - 1;
        while (r >= l) {
            int mid = (l + r) / 2;

            if (t[mid] <= b) {
                end = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        
        if (end >= start) ans += end - start + 1;
    }
    
    cout << ans;
    return 0;
}