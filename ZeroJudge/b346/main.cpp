#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left = -1;
    int right = -1;
    int parent = -1;
    int value = -1;
    int time = -1;
};

void solve(int parent, vector<Node> &v) {
    if (parent == -1) return;

    cout << v[parent].value << " ";

    solve(v[parent].left, v);
    solve(v[parent].right, v);
}

bool cmp(Node a, Node b) {
    return a.value < b.value;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n) {
        vector<Node> v(n);
        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            v[i].value = val;
            v[i].time = i;
        }
        sort(v.begin(), v.end(), cmp);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            int last = -1;
            while (!st.empty() && v[st.top()].time > v[i].time) {
                last = st.top();
                st.pop();
            }
            if (!st.empty()) {
                v[st.top()].right = i;
                v[i].parent = st.top();
            }
            if (last != -1) {
                v[i].left = last;
                v[last].parent = i;
            }
            st.push(i);
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (v[i].parent == -1) {
                root = i;
                break;
            }
        }
        solve(root, v);
        cout << '\n';
    }
    return 0;
}
