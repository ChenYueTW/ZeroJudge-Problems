#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    int x =  a % 10, y = b % 10;
    if (x == y) return a > b;
    else return x < y;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end(), cmp);
        for (int i : v) cout << i << " ";
        cout << '\n';
    }
    return 0;
}