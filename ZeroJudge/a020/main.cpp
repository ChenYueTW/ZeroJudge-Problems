#include <bits/stdc++.h>
using namespace std;

int m[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};

int main() {
    string n; cin >> n;
    int a = m[n[0] - 65];
    a = (a % 10) * 9 + a / 10;
    int b = 0;
    for (int i = 1; i < n.length(); i++) {
        b += (n[i] - '0') * (9 - i);
    }
    int ans = a + b + (n[n.length() - 1] - '0');
    if (ans % 10 == 0) cout << "real";
    else cout << "fake";
    return 0;
}
