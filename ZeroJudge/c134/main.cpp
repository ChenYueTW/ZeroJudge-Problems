#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    float ans = 0;
    int ansm = 0, ansshift = 0, ansrem = 0;
    for (int i = 2; i < sqrt(2 * n); i++) {
        int base = i * (i + 3) / 2;
        int extra = n - base;
        if (extra < 0) continue;
        int shift = extra / i, rem = extra % i;

        float cache = 0;
        for (int j = 2; j < i - rem + 2; j++) {
            cache += log10(j + shift);
        }
        for (int j = i - rem + 2; j <= i + 1; j++) {
            cache += log10(j + shift + 1);
        }
        if (cache > ans) {
            ans = cache;
            ansm = i;
            ansshift = shift;
            ansrem = rem;
        }
    }

    for (int i = 2; i <= ansm + 1; i++) {
        if (i <= ansm - ansrem + 1) cout << i + ansshift << " ";
        else cout << i + ansshift + 1 << " ";
    }
    cout << '\n' << '\n';
    //cout << ansm << " " << ansshift << " " << ansrem;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
