#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n) {
        if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) cout << "閏年";
        else cout << "平年";
        cout << '\n';
    }
    return 0;
}
