
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        unordered_map<char, int> mp;
        int siz = 0;
        bool f = 1, a = 1;
        for (int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {
                mp[tolower(s[i])]++;
                siz++;
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            // char c = it -> first;
            int t = it -> second;
            if (t % 2 != 0) {
                if (siz % 2 != 0 && f) {
                    f = 0;
                    continue;
                }
                a = 0;
                break;
            }
        }
        cout << (a ? "yes !" : "no...") << '\n';
    }
    return 0;
}