#include <bits/stdc++.h>
using namespace std;

int m[1005];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        m[a] = b;
    }
    int cache = m[1], temp = m[1];
    while (m[cache] != 0) {
        cache = m[cache];

        if (cache == temp)
    }
}
