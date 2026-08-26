#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        float sum = 0;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            sum += v;
        }
        sum /= n;
        cout << (sum > 59 ? "no" : "yes") << '\n';
    }
    return 0;
}