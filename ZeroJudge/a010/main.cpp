#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; cin >> n; t = n;
    vector<pair<int, int>> v;

    for (int i = 2; i * i <= t; i++) {
        while (n % i == 0) {
            if (v.empty()) v.push_back({i, 1});
            else if (v[v.size() - 1].first != i) v.push_back({i, 1});
            else v[v.size() - 1].second++;
            n/=i;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == 1) cout << v[i].first;
        else cout << v[i].first << "^" << v[i].second;

        if (i != v.size() - 1) cout << " * ";
    }
    if (n != 1) cout << (v.size() == 0 ? "" : " * ") << n;
    return 0;
}
