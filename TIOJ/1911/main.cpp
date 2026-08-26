#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    multiset<int> p;
    while (true) {
        int v;
        scanf("%d", &v);

        if (v == 0) {
            break;
        }
        if (v > 0) { // work
            p.insert(v);
        } else {
            if (p.empty()) continue;
            if (v == -2) { // high primary
                auto iter = p.end();
                --iter;
                cout << *iter << " ";
                p.erase(iter);
            } else { // low primary
                cout << *p.begin() << " ";
                p.erase(p.begin());
            }
        }
    }
    return 0;
}
