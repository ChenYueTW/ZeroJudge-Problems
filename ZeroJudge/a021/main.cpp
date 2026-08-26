#include<bits/stdc++.h>
using namespace std;

string a, b, oper;

vector<int> p(vector<int>& x, vector<int>& y) {
    int tmp = 0;
    vector<int> ans;
    for (int i = 0; i < y.size(); i++) {
        int num = x[x.size() - 1 - i] + y[y.size() - 1 - i];
        if (num > 9) {
            tmp++;
            continue;
        }
        ans.push_back(num + tmp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cin >> a >> oper >> b;
    vector<int> x(a.length()), y(b.length());
    for (int i = 0; i < a.length(); i++) x[i] = a[i] - '0';
    for (int i = 0; i < b.length(); i++) y[i] = b[i] - '0';

    if (oper == "+") {
        vector<int> ans = p(x, y);
        for (int i : ans) cout << i;
    }
    return 0;
}