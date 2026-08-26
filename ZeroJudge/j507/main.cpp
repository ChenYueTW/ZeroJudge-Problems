#include <bits/stdc++.h>
using namespace std;

int bit[100005];

int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= x & -x;
    }
    return sum;
}

void add(int x, int n) {
    while (x <= n) {
        bit[x] += 1;
        x += x & -x;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<int> v;
        int x;
        while (ss >> x) {
            v.push_back(x);
        }
        fill(bit, bit + 100005, 0);
        int ans = 0, temp = v[0];
        for (int i = 0 ; i < v.size(); i++) {
            ans += i - query(v[i]);
            add(v[i], v.size());
        }
        cout << ans << '\n';
    }
    return 0;
}
