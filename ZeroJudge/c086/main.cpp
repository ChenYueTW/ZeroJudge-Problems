#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, num = 1;
    while (scanf("%d", &n) != EOF) {
        int x;
        scanf("%d", &x);
        vector<int> v(n); // 0-based
        vector<int> t(20);
        for (int i = 0; i < n; i++) v[i] = i + 1;
        for (int i = 0; i < 20; i++) cin >> t[i];

        for (int i = 0; i < 20; i++) {
            if (v.size() == x) break;
            for (int j = t[i] - 1; j < v.size(); j += (t[i] - 1)) {
                v.erase(v.begin() + j);
                if (v.size() == x) break;
            }
            if (v.size() == x) break;
        }

        cout << "Selection #" << num << '\n';
        for (int i : v) cout << i << " ";
        cout << '\n' << '\n';
        num++;
    }
    return 0;
}
