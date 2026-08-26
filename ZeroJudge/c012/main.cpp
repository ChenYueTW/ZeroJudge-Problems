#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
    int va = a.first, vb = b.first;
    if (a.second == b.second) return va > vb;
    return a.second < b.second;
}

int main() {
    string s;
    while (getline(cin, s)) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        vector<pair<char, int>> p(mp.begin(), mp.end());
        sort(p.begin(), p.end(), cmp);
        for (pair<char, int> a : p) {
            int vv = a.first;
            cout << vv << " " << a.second << '\n';
        }
        cout << '\n';
    }
    return 0;
}
