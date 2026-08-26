#include <bits/stdc++.h>
using namespace std;

int l[35], r[35];

int dfs(int p, int depth) {
    if (p == -1) return depth;
    //cout << p << " " << depth << '\n';

    int leftd = 0, rightd = 0;
    depth++;
    if (l[p] != -1) {
        leftd = dfs(l[p], depth);
    } else {
        leftd = depth;
    }
    if (r[p] != -1) {
        rightd = dfs(r[p], depth);
    } else {
        rightd = depth;
    }
    return max(leftd, rightd);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int c, a, b;
        cin >> c >> a >> b;
        l[c] = a;
        r[c] = b;
    }

    cout << dfs(0, 1) - 2;
    return 0;
}
