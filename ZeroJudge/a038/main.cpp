#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool f = 1;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (f && s[i] == '0') continue;
        if (s[i] != '0' && f) f = 0;
        cout << s[i];
    }
    if (f) cout << 0;
    return 0;
}
