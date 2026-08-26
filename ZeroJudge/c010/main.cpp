#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    int n;
    cin >> n;
    cout << n << '\n';
    l.push(n);
    while (cin >> n) {
        if (n > l.top()) r.push(n);
        else l.push(n);

        int l_size = l.size(), r_size = r.size();
        if (r_size - l_size > 1) {
            int val = r.top();
            r.pop();
            l.push(val);
        } else if (l_size - r_size > 1) {
            int val = l.top();
            l.pop();
            r.push(val);
        }

        if ((l.size() + r.size()) % 2 != 0) {
            if (l.size() > r.size()) {
                cout << l.top() << '\n';
            } else {
                cout << r.top() << '\n';
            }
        } else {
            cout << (l.top() + r.top()) / 2 << '\n';
        }
    }
    return 0;
}
