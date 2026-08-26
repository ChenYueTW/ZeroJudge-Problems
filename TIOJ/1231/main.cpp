#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> p;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        p.push(make_pair(b, a));
    }
    int t;
    cin >> t;

    int ans = 0;
    for (int i = n - 1; i >= 0; i++) {
        if (p.top().first < t) {
            while(p.top().first == t) {
                t--;
                ans--;
            }
        }
        ans += p.top().second;
        p.pop();
        t-= 1;
    }
}
