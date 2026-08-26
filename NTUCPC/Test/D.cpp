#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    if (n <= 1000) {
        cout << 0 << " " << n;
    } else {
        int a = n / 2;
        int b = n - a;
        cout << a << " " << b;
    }
    return 0;
}
