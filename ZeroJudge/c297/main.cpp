#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<pair<int, vector<int>>> v(9);
    for (int i = 0; i < 9; i++) {
        int n; cin >> n;
        v[i].first = n;
        for (int j = 0; j < n; j++) {
            int val;
            string s; cin >> s;
            if (s == "1B") val = 1;
            else if (s == "2B") val = 2;
            else if (s == "3B") val = 3;
            else if (s == "HR") val = 4;
            else val = -1;
            v[i].second.push_back(val);
        }
    }
    int b; cin >> b;
    bool one = 0, two = 0, three = 0;
    int score = 0, out = 0, round = 0, in = 0, l = 0;
    while (l < b) {
        int val = v[round % 9].second[round / 9];

        if (val > 0) {
            if (val == 1) {
                if (three) {
                    three = 0;
                    score++;
                }
                if (two) {
                    three = 1;
                    two = 0;
                }
                if (one) {
                    two = 1;
                    one = 0;
                }
                one = 1;
            } else if (val == 2) {
                if (three) {
                    three = 0;
                    score++;
                }
                if (two) {
                    two = 0;
                    score++;
                }
                if (one) {
                    three = 1;
                    one = 0;
                }
                two = 1;
            } else if (val == 3 || val == 4) {
                if (three) {
                    three = 0;
                    score++;
                }
                if (two) {
                    two = 0;
                    score++;
                }
                if (one) {
                    one = 0;
                    score++;
                }
                if (val == 3) three = 1;
                if (val == 4) score++;
            }
        } else {
            out++;
            l++;
        }
        round++;
        if (out == 3) {
            one = 0, two = 0, three = 0;
            out = 0;
        }
    }
    cout << score;
    return 0;
}
