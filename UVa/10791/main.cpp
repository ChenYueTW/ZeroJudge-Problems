#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, c = 1;
    while (cin >> n) {
        if (n == 0) break;
        int cache = n;
        map<int, int> mp;
        for (int i = 2; i <= sqrt(n); i++) {
            while (n % i == 0) {
                mp[i]++;
                n /= i;
            }
        }
        if (n != 1) mp[n]++;
        if (mp.size() == 1) {
            cout << "Case " << c << ": " << cache + 1 << '\n';
            c++;
            continue;
        }
        long long ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans += round(pow(it -> first, it -> second));
        }
        cout << "Case " << c << ": " << ans << '\n';
    }
}
