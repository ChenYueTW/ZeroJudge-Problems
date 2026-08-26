#include <bits/stdc++.h>
using namespace std;

pair<int, int> ans[1005];
int m[1005];

void dfs(int p) {
    int left = ans[p].first;
    int right = ans[p].second;
    cout << m[p] << " ";
    if (left != -1) dfs(left);
    if (right != -1) dfs(right);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n) {
        vector<pair<int, int>> v(n);
        memset(m, 0, sizeof(m));
        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            v[i] = {val, i};
            m[i] = val;
        }
        sort(v.begin(), v.end());

        stack<int> s;
        fill(ans, ans+1005, make_pair(-1, -1));
        for (int i = 0; i < n; i++) {
            int last = -1;
            if (!s.empty() && s.top() > v[i].second) {
                while (!s.empty() && s.top() > v[i].second) {
                    last = s.top();
                    s.pop();
                }
            }
            if (last != -1) {
                ans[v[i].second].first = last;
            }
            if (!s.empty()) {
                ans[s.top()].second = v[i].second;
            }
            s.push(v[i].second);
        }
        int root = 0;
        while(!s.empty()) {
            root = s.top();
            s.pop();
        }
        dfs(root);
        cout << '\n';
    }
}
