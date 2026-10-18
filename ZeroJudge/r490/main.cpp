#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int c = s[12] - '0';
        string source = s.substr(0, 3);
        int odd = 0, even = 0;
        for (int i = 0; i < 12; i++) {
            if (i % 2 == 0) odd += (s[i] - '0');
            else even += (s[i] - '0');
        }
        int cert = (odd + 3 * even) % 10 + c;
        if (cert == 10 || cert == 0) {
            m[source]++;
        }
    }
    string ansstr;
    int ans = 0;
    for (auto &pair : m) {
        if (pair.second > ans) {
            ansstr = pair.first;
            ans = pair.second;
        }
    }
    cout << ansstr << " " << ans;
    return 0;
}