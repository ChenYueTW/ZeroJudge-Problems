#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    while (cin >> t) {
        unordered_map<string, int> m;

        for (int i = 0; i < t; i++) {
            string s;
            cin >> s;

            if (m[s] == 0) {
                m[s] = m.size();
                cout << "New! " << m[s] << '\n';
            } else {
                cout << "Old! " << m[s] << '\n';
            }
        }
    }
    return 0;
}
