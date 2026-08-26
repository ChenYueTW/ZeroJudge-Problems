#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            if (c == 1) {
                v.pop_back();
            } else if (c == 2) {
                cout << v.back() << endl;
            } else if (c == 3) {
                int value;
                cin >> value;
                v.push_back(value);
            }
        }
    }
    return 0;
}
