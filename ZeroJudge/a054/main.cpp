
#include<bits/stdc++.h>
using namespace std;

int mp[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};

int main() {
    int s, sum = 0, last;
    cin >> s;
    last = s % 10;
    s /= 10;
    for (int i = 0; i < 8; i++) {
        sum += (s % 10) * (i + 1);
        s /= 10;
    }
    for (int i = 0; i < 26; i++) {
        int num = mp[i];
        int total = sum + (num % 10) * 9;
        num /= 10;
        total += (num % 10);
        int c = 10 - (total % 10);
        if (c == 10) c = 0;
        if (c == last) {
            char ans = 65 + i;
            cout << ans;
        }
    }
    return 0;
}