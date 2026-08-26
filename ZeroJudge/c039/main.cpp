#include<bits/stdc++.h>
using namespace std;

int caculate(int value, int time) {
    if (value == 1) return time;

    if (value % 2 != 0) return caculate(3 * value + 1, time + 1);
    else return caculate(value / 2, time + 1);
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int ans = -1, ti, tj;
        if (i < j) {ti = i; tj = j;}
        else {ti = j; tj = i;}
        for (int a = ti; a <= tj; a++) {
            ans = max(ans, caculate(a, 1));
        }
        cout << i << " " << j << " " << ans << '\n';
    }
    return 0;
}
