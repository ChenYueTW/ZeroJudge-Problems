#include <bits/stdc++.h>
using namespace std;

string solve(string a, string b) {
    if (a.size() == 0) return "";
    if (a.size() == 1) return a;
    char root = a[0];
    int bIndex = b.find(root);

    string lefta = a.substr(1, bIndex);
    string righta = a.substr(bIndex + 1, a.size());
    string leftb = b.substr(0, bIndex);
    string rightb = b.substr(bIndex + 1, b.size());

    return solve(lefta, leftb) + solve(righta, rightb) + root;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string pre;
    while(cin >> pre) {
        string in;
        cin >> in;

        cout << solve(pre, in) << '\n';
    }
    return 0;
}
