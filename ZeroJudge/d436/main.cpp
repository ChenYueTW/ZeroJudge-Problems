#include<bits/stdc++.h>
using namespace std;

string s;
vector<char> tmp;
bool alive[11];

void dfs(int step) {
    if (tmp.size() == s.length()) {
        for (char c : tmp) cout << c;
        cout << '\n';
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        if (i > 0 && s[i] == s[i - 1] && !alive[i - 1]) continue;
        if (alive[i]) continue;
        alive[i] = 1;
        tmp.push_back(s[i]);
        dfs(i + 1);
        tmp.pop_back();
        alive[i] = 0;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        memset(alive, 0, sizeof(alive));
        cin >> s;
        sort(s.begin(), s.end());
        dfs(0);
        cout << '\n';
    }
    return 0;
}
