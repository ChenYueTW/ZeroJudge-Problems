#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), a(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && v[i] > v[st.top()]) {
            st.pop();
        }

        if (st.empty()) {
            ans = n - i - 1;
        } else {
            ans = st.top() - i;
        }
        st.push(i);
        a[i] = ans;
    }

    for (int i : a) cout << i << '\n';

    return 0;
}
