#include<bits/stdc++.h>
using namespace std;

bitset<100000005> mp;

int main() {
    mp[1] = 1;
    for (int i = 2; i < sqrt(100000005); i++) {
        if (mp[i]) continue;
        for (int j = i + i; j <= 100000000; j += i) {
            mp[j] = 1;
        }
    }
    int a, b;
    while (cin >> a >> b) {
        int ans = 0;
        for (int i = a; i <= b; i++) if (!mp[i]) ans++;
        cout << ans << '\n';
    }
    return 0;
}