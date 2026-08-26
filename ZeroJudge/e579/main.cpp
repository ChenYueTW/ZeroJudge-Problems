#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;
    bitset<3652> day;
    for (int i = 0; i < p; i++) {
        int hi; cin >> hi;
        for (int j = hi; j <= n; j += hi) {
            if (j % 7 == 0 || (j - 6) % 7 == 0) continue;
            day[j] = 1;
        }
    }
    //for (int i = 0; i < n; i++) cout << day[i] << " ";
    cout << day.count() << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
