#include <bits/stdc++.h>
using namespace std;

bool c[1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    stack<int> s, r;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = 0;
    }

    int require = 1;
    bool f = true;

    while (f) {
        f = false;
        if (c[require] == 1) {
            if (s.top() != require && r.size() < m) {
                int val = s.top();
                r.push(val);
                c[val] = 0;
                f = true;
            } else if (s.top() == require) {
                require++;
                f = true;
            }
            s.pop();

            if (require == n + 1) {
                cout << "yes";
                break;
            }
            continue;
        }

        if (r.size() == 0 && !a.empty()) {
            // A to Station
            if (a[0] != require) {
                s.push(a[0]);
                c[a[0]] = 1;
            } else if (a[0] == require) {
                // A to B
                require++;
            }
            a.erase(a.begin());
            f = true;
        } else if (r.size() != 0 && r.size() <= m && !c[require]) {
            int val = r.top();
            s.push(val);
            r.pop();
            c[val] = 1;
            f = true;
        }

        if (require == n + 1) {
            cout << "yes";
            break;
        }
    }
    if (!f) {
        cout << "no";
    }
    return 0;
}
