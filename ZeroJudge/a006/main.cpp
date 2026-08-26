#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    double temp = b * b - 4 * a * c;
    if (temp == 0) cout << "Two same roots x=" << (-b / 2 / a);
    else if (temp < 0) cout << "No real root";
    else cout << "Two different roots x1=" << ((-b + sqrt(temp)) / 2 / a) << " , x2=" << ((-b - sqrt(temp)) / 2 / a);

    return 0;
}
