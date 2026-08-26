#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    bool f = 1;
    cin >> n >> m;
    for (int i = n; i < m; i++) {
        int index = 0;
        while (pow(10, index) < i) index++;
        int c = i, t = 0;
        while (c >= 1) {
            t += round(pow(c % 10, index));
            c /= 10;
        }
        if (t == i) {cout << i << " "; f = 0;}
    }
    if (f) cout << "none";
    return 0;
}
