#include <bits/stdc++.h>
using namespace std;

int v[500005], m[500005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q, ans = 0;
    set<int> wrong;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        v[i] = i;
        m[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        // a must < b
        if (a != b) {
            if (a > b) swap(a, b);
        } else {
            if (t == 2) {
                cout << 0 << '\n';
            }
            continue;
        }

        if (t == 1) {
            int aInx = m[a], bInx = m[b];
            m[v[a]] = b, m[v[b]] = a;
            swap(v[a], v[b]);

            if (v[a] != a) wrong.insert(a);
            else wrong.erase(a);

            if (v[b] != b) wrong.insert(b);
            else wrong.erase(b);
        } else {
            ans = 0;
            auto iter = wrong.lower_bound(a);
            //cout << *iter << " " << *hiter << endl;
            while (iter != wrong.end() && *iter <= b) {
                int x = *iter;

                ans++;
                int orinindex = m[*iter];

                m[v[x]] = m[x];
                m[x] = x;
                swap(v[orinindex], v[x]);

                wrong.erase(iter);
                if (v[orinindex] == orinindex) {
                    wrong.erase(orinindex);
                }
                iter = wrong.lower_bound(x);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
