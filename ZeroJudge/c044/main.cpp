#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    unordered_map<char, int> mp;
    string s;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ' ') continue;
            int val = s[j];
            if ((val >= 65 && val <= 90) || (val >= 97 && val <= 122)) {
                char c = toupper(s[j]);
                mp[c]++;
            }
        }
    }
    vector<pair<char, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), cmp);
    for (pair<char, int> p : vec) {
        string ss{p.first};
        cout << ss << " " << p.second << '\n';
    }
    return 0;
}
