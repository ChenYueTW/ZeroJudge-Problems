#include <bits/stdc++.h>
using namespace std;

void sear(int l, int r, string s) {
    if (r > l) return;
    int mid = (l + r) / 2;
    string leftstr, rightstr;
    // left
    cout << mid - l + 1;
    for (int i = l; i <= mid; i++) {
        cout << i << " ";
    }
    cout << flush;
    cin >> leftstr;

    if (leftstr == s) {
        sear(l, mid, s);
        return;
    } else if (s == "even" && leftstr == "odd" && rightstr == "odd") {
        sear(l, mid, "odd");
        sera(mid + 1, r, "odd");
    }
    sear(mid + 1, r, s);
}

int main() {
    string ans;
    while (cin >> ans) {
        if (ans == "correct") break;
        string a, b;
        cout << 100;
        for (int i = 1; i <= 100; i++) {
            cout << i << " ";
        }
        cout << flush;
        cin >> a;
        cout << 100;
        for (int i = 101; i <= 200; i++) {
            cout << i << " ";
        }
        cout << flush;
        cin >> b;
        sear(0, 100, a);
        sear(101, 200, b);
    }
}
