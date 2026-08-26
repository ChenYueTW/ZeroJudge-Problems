#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    return 2 * x - 3;
}

int g(int x, int y) {
    return 2 * x + y - 7;
}

int h(int x, int y, int z) {
    return 3 * x - 2 * y + z;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // f -> 2000
    // g -> 2001
    // h -> 2002
    string s;
    vector<int> v;
    stack<int> st;

    while (cin >> s) {
        if (s == "f") {
            v.push_back(2000);
        } else if (s == "g") {
            v.push_back(2001);
        } else if (s == "h") {
            v.push_back(2002);
        } else {
            int val = stoi(s);
            v.push_back(val);
        }
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] != 2000 && v[i] != 2001 && v[i] != 2002) { // is number
            st.push(v[i]);
        } else if (v[i] == 2002) {
            int x, y, z;
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            z = st.top();
            st.pop();

            st.push(h(x, y, z));
        } else if (v[i] == 2000) {
            int x;
            x = st.top();
            st.pop();

            st.push(f(x));
        } else {
            int x, y;
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();

            st.push(g(x, y));
        }
    }
    cout << st.top();

    return 0;
}
