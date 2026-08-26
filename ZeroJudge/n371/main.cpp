#include <bits/stdc++.h>
using namespace std;

bitset<1000005> arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, l;
    cin >> n >> m;
    vector<int> nxt(n + 5);

    for (int i = 1; i <= n + 1; i ++) {
        nxt[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        if (arr[x] == 1) {
            cout << "我大意了啊~沒有閃" << '\n';
            continue;
        }

        int first = nxt[x], second = nxt[first];
        if (second > n) {
            cout << "來~ 騙" << '\n';
            continue;
        }
        nxt[first] = nxt[second];
        arr[second] = 1;
        cout << second << '\n';
    }

    return 0;
}
