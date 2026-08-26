#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    while(cin >> n) {
        vector<int> map;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            map.push_back(v);
        }
        sort(map.begin(), map.end());
        for (int i = 0; i < n; i++) {
            cout << map.at(i) << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
}
