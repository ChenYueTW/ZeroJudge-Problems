#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    int s = (a * 2 + b) % 3;
    if (s == 0) cout << "普通";
    else if (s == 1) cout << "吉";
    else cout << "大吉";
    return 0;
}
