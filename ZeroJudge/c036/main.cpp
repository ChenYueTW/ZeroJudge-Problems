#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int h, u, d;
    float f;
    while (cin >> h >> u >> d >> f) {
        if (h == 0) break;
        float height = 0, cnt = u, day = 0;
        while (height >= 0 && height < h) {
            day++;
            if (cnt > 0) height += cnt;
            if (height > h) break;
            cnt -= (u * (f / 100));
            height -= d;

            if (height < 0) break;

        }
        if (height <= 0) cout << "failure on day " << day << '\n';
        else cout << "success on day " << day << '\n';
    }
    return 0;
}
