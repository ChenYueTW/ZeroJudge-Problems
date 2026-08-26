#include <bits/stdc++.h>
using namespace std;

int tablenum[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string tablelo[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int exchange(char c) {
    if (c == 'M') return 1000;
    else if (c == 'D') return 500;
    else if (c == 'C') return 100;
    else if (c == 'L') return 50;
    else if (c == 'X') return 10;
    else if (c == 'V') return 5;
    else return 1;
}

int main() {
    string a, b;
    while (cin >> a) {
        if (a == "#") break;
        cin >> b;

        int aval = 0, bval = 0;
        for (int i = 0; i < a.length(); i++) {
            if (i != a.length() - 1 && exchange(a[i]) < exchange(a[i + 1])) {
                aval -= exchange(a[i]);
            } else {
                aval += exchange(a[i]);
            }
        }
        for (int i = 0; i < b.length(); i++) {
            if (i != b.length() - 1 && exchange(b[i]) < exchange(b[i + 1])) {
                bval -= exchange(b[i]);
            }
            else bval += exchange(b[i]);
        }
        //aval += (a[a.length() - 1] < )
        //bval += exchange(b[b.length() - 1]);

        int ans = abs(aval - bval);
        if (ans == 0) {
            cout << "ZERO" << '\n';
            continue;
        }
        string sans = "";
        for (int i = 0; i < 13; i++) {
            while (tablenum[i] <= ans) {
                sans += tablelo[i];
                ans -= tablenum[i];
            }
        }

        cout << sans << '\n';
    }

    return 0;
}
