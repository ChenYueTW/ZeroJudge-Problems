#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    // b > a
    while(true) {
        if (a > b) swap(a, b);
        c = b % a;
        if (c == 0) break;
        b = c;
    }
    cout << a;
    return 0;
}
