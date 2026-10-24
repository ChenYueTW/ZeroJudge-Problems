#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int p = 0;
    int num = 0;
    vector<int> c;
};

Node v[100005];
vector<int> leaf;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 0) {
            leaf.push_back(i + 1);
        } else {
            for (int j = 0; j < k; j++) {
                int val; cin >> val;
                v[val].p = i + 1;
                v[i + 1].c.push_back(val);
            }
        }
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].p == 0 && !v[i].c.empty()) {
            root = i;
            break;
        }
    }
    for (int i : leaf) {
        int parent = v[i].p;
        int child = i;
        while (v[parent].num <= v[child].num) {
            v[parent].num = v[child].num + 1;
            child = parent;

            if (v[parent].p == 0) break;
            parent = v[parent].p;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += v[i].num;
    }
    cout << root << '\n';
    cout << ans;
    return 0;
}