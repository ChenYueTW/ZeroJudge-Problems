#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int pNum = 0, qNum = 0, ans = 0;
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'p') {
                pNum++;
            } else if (s[j] == 'q') {
                qNum++;

                if (pNum != 0) {
                    pNum--;
                    qNum--;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}