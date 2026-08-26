#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (cin >> a) {
        cin >> b;
        vector<vector<int>> v(a, vector<int>(b, 0));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                cout << v[j][i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
