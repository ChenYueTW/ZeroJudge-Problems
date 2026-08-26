#include<bits/stdc++.h>
using namespace std;

int main() {
    int left = 1, right = 1024;
    cout << (left + right) / 2 << '\n';
    cout << flush;
    string s;
    while (cin >> s) {
        if (s == "=") break;
        int mid = (left + right) / 2;

        if (s == "<") {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

        cout << (left + right) / 2 << '\n';
        cout << flush;
    }
    return 0;
}
