#include <bits/stdc++.h>
using namespace std;

int w[100000], f[100000], id[100000];

bool cmb(int a, int b) {
    return w[a] * f[b] < w[b] * f[a];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        id[i] = i;
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    sort(id, id + n, cmb);

    long long ans = 0, total = 0;
    for (int i = 1; i < n; i++) {
        total += w[id[i - 1]];
        ans += (total * f[id[i]]);
    }
    cout << ans;
    return 0;
}
