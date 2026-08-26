#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool f = 0;
    cin >> s;
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            f = 1;
            break;
        }
    }
    if (!f) cout << "yes";
    else cout << "no";
    return 0;
}
