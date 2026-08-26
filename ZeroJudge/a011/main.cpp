#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    while (getline(cin, s)) {
        int ans = 0;
        bool f = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                if (!f) f = 1;
            } else {
                if (f) {
                    ans++;
                    f = 0;
                }
            }
        }
        if (isalpha(s.back())) ans++;
        cout << ans << '\n';
    }
    return 0;
}
