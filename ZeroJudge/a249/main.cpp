#include <bits/stdc++.h>
using namespace std;

int dfs(int index, int i, int depth, int limit) {
    if (depth == limit) {
        return index;
    }
    depth++;
    if (i % 2 == 0) { // right
        return dfs(index * 2 + 1, i / 2, depth, limit);
    } else { // left
        return dfs(index * 2, (i + 1) / 2, depth, limit);
    }
}

int main() {
    //ios::sync_with_stdio(0), cin.tie(0);
    int t;
    scanf("%d", &t);

    while (t--) {
        int d, i, ans = 0;
        scanf("%d %d", &d, &i);

        ans = dfs(1, i, 1, d);
        printf("%d\n", ans);
    }
    return 0;
}
