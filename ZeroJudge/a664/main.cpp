#include <bits/stdc++.h>
using namespace std;

int getans(stack<char> q, queue<char> part) {
    queue<char> p;
    if (q.front() == '(') {
        q.pop();
        return getans(q, p);
    } else { // is number
        while (true) {
            if (q.front() != '+' || q.front() != '-' || q.front() != '*' || q.front() != '/') {
                char c = q.front();
                part.push(c);
            } else {
                break;
            }
        }
        int frontNum = 0;
        while (q.size() > 0) {
            frontNum += pow(10, q.size() - 1) * (q.front() - '0');
            q.pop();
        }
    }
}

int main() {
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack<char> v;
        for (int i = 0; i < s.length(); i++) {
            v.push(s[i]);
        }

        int ans = getans(v, 0);
        cout << ans;
    }
    return 0;
}
