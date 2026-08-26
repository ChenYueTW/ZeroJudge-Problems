#include <bits/stdc++.h>
using namespace std;

void move(char start, char mid, char end, int n) {
    if (n == 0) return;
    move(start, end, mid, n - 1);
    cout << "Move ring " << n << " from " << start << " to " << end << endl;
    move(mid, start, end, n - 1);
}

int main() {
    int n = 0;
    while(cin >> n) {
        move('A', 'B', 'C', n);
    }
    return 0;
}
