#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

unordered_map<string, ll> mp;

string exchange(ll a, ll b) {
    return to_string(a) + " " + to_string(b);
}

ll dfs(ll half, ll zero) {
    ll c = 0;
    if (half + zero < 2) {
        return 1;
    }

    if (half == 0 && zero > 1) {
        ll a = (zero * (zero - 1) / 2) % MOD, b, val = mp[exchange(2, zero - 2)];
        if (val != 0) b = val;
        else {
            b = dfs(2, zero - 2) % MOD;
            mp[exchange(2, zero - 2)] = b;
        }
        return (a * b) % MOD;
    } else if (zero == 0) {
        // C half get 2
        ll a = (half * (half - 1) / 2) % MOD, b, val = mp[exchange(half - 2, 0)];
        if (val != 0) b = val;
        else {
            b = dfs(half - 2, 0);
            mp[exchange(half - 2, 0)] = b;
        }
        return (a * b) % MOD;
    }
    // all half
    if (half > 1) {
        ll a = (half * (half - 1) / 2) % MOD, b, val = mp[exchange(half - 2, zero)];
        if (val != 0) b = val;
        else {
            b = dfs(half - 2, zero) % MOD;
            mp[exchange(half - 2, zero)] = b;
        }
        c += (a * b) % MOD;
    }
    // all zero
    if (zero > 1) {
        ll a = (zero * (zero - 1) / 2) % MOD, b, val = mp[exchange(half + 2, zero - 2)];
        if (val != 0) b = val;
        else {
            b = dfs(half + 2, zero - 2) % MOD;
            mp[exchange(half + 2, zero - 2)] = b;
        }
        c += (a * b) % MOD;
    }
    // half and zero
    if (half > 0 && zero > 0) {
        ll a = half * zero % MOD, b, val = mp[exchange(half, zero - 1)];
        if (val != 0) b = val;
        else {
            b = dfs(half, zero - 1) % MOD;
            mp[exchange(half, zero - 1)] = b;
        }
        c += (a * b) % MOD;
    }
    return c % 1000000007;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int zero = 0, half = 0;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val == 0) zero++;
        else if (val == 1) half++;
    }
    cout << dfs(half, zero) % MOD;
    return 0;
}
