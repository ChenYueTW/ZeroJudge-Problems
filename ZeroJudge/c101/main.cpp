#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.second.length() != b.second.length()) return a.second.length() < b.second.length();
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    vector<pair<int, string>> v;
    set<string> exist;
    while(cin >> s) {
        if (s == "()") {
            sort(v.begin(), v.end(), cmp);
            if (exist.size() != v.size() || v[0].second != "") {
                cout << "not complete" << '\n';
                v.clear();
                exist.clear();
                continue;
            }
            bool cur = 0;

            for (int i = 0; i < v.size(); i++) {
                string check = v[i].second;
                if (check != "") check = check.substr(0, check.length() - 1);

                if (exist.find(check) == exist.end()) cur = 1;
            }

            if (!cur) {
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i].first << (i == v.size() - 1 ? "" : " ");
                }
            } else cout << "not complete";
            cout << '\n';
            v.clear();
            exist.clear();
            continue;
        }
        int markIndex = s.find(',');
        int left = stoi(s.substr(1, markIndex - 1));
        string right = s.substr(markIndex + 1, s.length() - markIndex - 2);
        v.push_back({left, right});
        exist.insert(right);
    }
    return 0;
}
