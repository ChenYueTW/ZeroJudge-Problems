#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    int n;
    double num = 0;
    cin >> n;
    multiset<int> a, b;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (i == 0) {
            a.insert(v);
            num = v;
            printf("%.6f\n", num);
            continue;
        }

        if (v >= num) {
            b.insert(v);
        } else {
            a.insert(v);
        }

        // check
        int aSize = a.size();
        int bSize = b.size();
        if (abs(aSize - bSize) > 1) {
            if (aSize > bSize) {
                auto it = prev(a.end());
                b.insert(*it);
                a.erase(it);
            } else {
                auto it = b.begin();
                a.insert(*it);
                b.erase(it);
            }
        }

        aSize = a.size();
        bSize = b.size();
        if ((aSize + bSize) % 2 == 0) {
            num = ((double)*a.rbegin() + (double)*b.begin()) / 2.0;
        } else {
            if (aSize > bSize) {
                num = *a.rbegin();
            } else {
                num = *b.begin();
            }
        }
        printf("%.6f\n", num);

    }

    return 0;
}
