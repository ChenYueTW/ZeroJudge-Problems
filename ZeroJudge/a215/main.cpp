#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int ans = 1, num = n;
        while (n <= m) {
            ans++;
            num++;
            n += num;
        }
        cout << ans << '\n';
    }
    return 0;
}