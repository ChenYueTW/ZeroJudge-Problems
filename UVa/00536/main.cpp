#include<bits/stdc++.h>
using namespace std;

void dfs(string a, string b) {
    if (a.length() == 0 && b.length() == 0) return;
    char root = a[0];
    int index = b.find(root);
    dfs(a.substr(1, index), b.substr(0, index));
    dfs(a.substr(index + 1, a.length()), b.substr(index + 1, b.length()));
    cout << root;
}

int main() {
    string a;
    while (cin >> a) {
        string b;
        cin >> b;
        dfs(a, b);
        cout << '\n';
    }
    return 0;
}