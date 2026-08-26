#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dfs(int p) {
    ios::sync_with_stdio(0), cin.tie(0);
    ll x;
    cin >> x;

    if (x == 0) return 0;

    if (x % 2 == 0) {
        return abs(x - p) + dfs(x) + dfs(x);
    } else {
        return abs(x - p) + dfs(x) + dfs(x) + dfs(x);
    }
}

int main() {
    ll root;
    cin >> root;

    if (root % 2 == 0) {
        cout << dfs(root) + dfs(root);
    } else {
        cout << dfs(root) + dfs(root) + dfs(root);
    }
    return 0;
}
