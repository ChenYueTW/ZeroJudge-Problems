#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    set<string> s;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if ((!s.empty() && s.find(a) == s.end()) || s.empty()) {
            s.insert(a);
            cout << "welcome, " << b << '\n';
        } else {
            cout << b << " account has been used" << '\n';
        }
    }
    return 0;
}
