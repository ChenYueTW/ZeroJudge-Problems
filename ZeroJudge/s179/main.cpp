#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll w[100005], total[100005];
int k = 0;

ll getS(int l, int r) {
    if (l > r) return 0;
    return total[r] - total[l - 1];
}

void binary(int l, int r, ll slr, ll a, ll b, int left) {
    if (l > r) return;
    int mid = (l + r) / 2;
    ll lk = getS(left, mid);

    if (lk * (a + b) >= a * slr && getS(left, mid - 1) * (a + b) < a * slr) {
        k = mid;
        return;
    }

    if (lk * (a + b) < a * slr) binary(mid + 1, r, slr, a, b, left);
    else binary(l, mid - 1, slr, a, b, left);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    total[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        total[i] = total[i - 1] + w[i];
    }

    for (int i = 0; i < m; i++) {
        k = 0;
        int l, r;
        ll a, b, slr;
        cin >> l >> r >> a >> b;
        slr = getS(l, r);
        binary(l, r, slr, a, b, l);
        
        cout << k << '\n';
    }
    return 0;
}