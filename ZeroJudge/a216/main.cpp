#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[30005], g[30005];

int main() {
    f[1] = 1; g[1] = 1;
    for (int i = 2; i < 30002; i++) {
        f[i] = i + f[i - 1];
        g[i] = f[i] + g[i - 1];
    }
    int n;
    while (cin >> n) {
        cout << f[n] << " " << g[n] << '\n';
    }
    return 0;
}