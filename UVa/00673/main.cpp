#include<bits/stdc++.h>
using namespace std;

stack<char> k;

void solve() {
    k = {};
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (!k.empty() && s[i] == ')' && k.top() == '(') k.pop();
        else if (!k.empty() && s[i] == ']' && k.top() == '[') k.pop();
        else k.push(s[i]);
    }
    cout << ((k.empty()) ? "Yes" : "No") << '\n';
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}