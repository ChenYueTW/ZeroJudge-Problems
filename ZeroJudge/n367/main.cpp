#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    double x = (a - b + c) / 2.0, y = (a + b - c) / 2.0, z = (-a + b + c) / 2.0;

    if  (x * y + y * z + z * x > 0) {
        printf("%.4f\n", x);
        printf("%.4f\n", y);
        printf("%.4f\n", z);
        double value = sqrt(x * y + y * z + z * x) / 2;
        printf("%.4f", value);
    } else {
        cout << "error";
    }
    return 0;
}
