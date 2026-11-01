#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mp[1030][1030];
queue<int> df;
ll ans = 0;
int n;

void dfs(int r, int c, int n) {
    if (df.front() != 0 && df.front() != 1) {
        df.pop();
        dfs(r, c, n / 2);
        dfs(r + n / 2, c, n / 2);
        dfs(r, c + n / 2, n / 2);
        dfs(r + n / 2, c + n / 2, n / 2);
        return;
    }
    if (df.front() == 1) {
        ans += n * n;
    }
    df.pop();
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s; cin >> s;
    for (char c : s) df.push(c - '0');
    cin >> n;
    dfs(0, 0, n);
    cout << ans;
    return 0;
}