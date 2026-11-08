#include<bits/stdc++.h>
using namespace std;

int n, l;
pair<int, int> t[100005];
stack<pair<int, int>> s;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> t[i].first;
    for (int i = 0; i < n; i++)
        cin >> t[i].second;

    int ans = 0, highest = 0;
    if (t[0].first - t[0].second < 0) {
        s.push(t[0]);
    } else {
        ans++;
        highest = t[0].second;
    }
    for (int i = 1; i < n; i++) {
        int loc = t[i].first, high = t[i].second;
        while (!s.empty() && s.top().first + s.top().second <= loc) {
            ans++;
            highest = max(highest, s.top().second);
            s.pop();
        }
        if (!s.empty() && loc - high >= s.top().first) {
            ans++;
            highest = max(highest, high);
        } else if (s.empty() && loc - high >= 0) {
            ans++;
            highest = max(highest, high);
        } else s.push(t[i]);
    }
    while(!s.empty() && s.top().first + s.top().second <= l) {
        ans++;
        highest = max(highest, s.top().second);
        s.pop();
    }
    cout << ans << '\n';
    cout << highest;
    return 0;
}