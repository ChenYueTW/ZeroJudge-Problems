#include<bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, y1, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int a = (x2 - x1) * (x2 - x1);
        int b = y2 - y1;
        int c = -2 * x1 * (y2 - y1);
        int d = x1 * x1 * (y2 - y1) + y1 * (x2 - x1) * (x2 - x1);
        int r = gcd(a, b);
        r = gcd(r, c);
        r = gcd(r, d);
        
        cout << a / r << "y " << "= " << b / r << "x^2 + " << c / r << "x + " << d / r << '\n';
    }
    return 0;
}