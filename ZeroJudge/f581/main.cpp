#include<bits/stdc++.h>
using namespace std;
#define ll long long

int orin[200005];
ll p[400005];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> orin[i];
        if (i != 0) p[i] = p[i - 1] + orin[i];
        else p[i] = orin[i];
    }
    for (int i = n; i < 2 * n + 1; i++) {
        p[i] += p[i - 1] + orin[i - n];
    }
    int index = 0;
    ll stay = 0;
    for (int i = 0; i < m; i++) {
        int q; cin >> q;
        int L = index, R = 2 * n;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (p[mid] - (i == 0 ? 0 : stay) < q) L = mid + 1;
            else { R = mid - 1; index = mid; }
        }
        stay = p[index % n];
        index = (index + 1) % n;
    }
    cout << index;
}