#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > v(n);


    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;

        // a friends add
        vector<int> av = v[a - 1];
        av.push_back(b);
        v[a - 1] = av;

        vector<int> bv = v[b - 1];
        bv.push_back(a);
        v[b - 1] = bv;
    }

    for (int i = 0; i < n; i++) {
        vector<int> c = v[i];
        sort(c.begin(), c.end());
        for (int j = 0; j < c.size(); j++) {
            cout << c[j] << (j == c.size() - 1 ? "" : " ");
        }
        cout << '\n';
    }
    return 0;
}
