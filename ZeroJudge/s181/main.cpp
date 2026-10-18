#include<bits/stdc++.h>
using namespace std;

vector<int> v(200), cache, cls(20);
bitset<10> b;
int k, m, r, t, ans = 0;

int getClass(int n) {
    return (n - 1) / r + 1;
}

void dfs(int start) {
    if (cache.size() == k) {
        ans++;
        if (ans == t) for (int c : cache) cout << c << " ";
        return;
    }
    for (int i = start; i <= m * r; i++) {
        if (b[v[i]] || cls[getClass(i)] >= 2) continue;
        cache.push_back(i);
        b[v[i]] = 1;
        cls[getClass(i)]++;
        dfs(i + 1);
        cache.pop_back();
        b[v[i]] = 0;
        cls[getClass(i)]--;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n >> m >> r >> k >> t;
    for (int i = 1; i <= m * r; i++) cin >> v[i];
    dfs(1);
    return 0;
}