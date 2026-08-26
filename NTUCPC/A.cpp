#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
}
