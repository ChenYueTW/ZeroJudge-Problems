#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, ans = 1;
        cin >> n;
        if (n == 0) ans = 0;
        while (n > 1) {
            ans *= (n % 10);
            n /= 10;
        }
        cout << ans << '\n';
    }
    return 0;
}