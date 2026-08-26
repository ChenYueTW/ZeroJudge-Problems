#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 10) cout << n * 6;
    else if (n >= 11 && n <= 20) cout << 60 + (n - 10) * 2;
    else if (n >= 21 && n <= 40) cout << 80 + (n - 20);
    else cout << 100;
    return 0;
}