#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m;

ll caculate(ll a, ll b) {
    a %= m;
    if (b == 1 || b == 0) return a % m;

    if (b % 2 == 0) {
        return caculate(a * a, b / 2) % m;
    } else {
        return a * caculate(a, b - 1) % m;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll b, p;
    while (cin >> b >> p >> m)  {
        cout << caculate(b, p) << '\n';
    }
    return 0;
}
