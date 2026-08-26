#include<bits/stdc++.h>
using namespace std;

bitset<1300005> prime;

int main() {
    prime[1] = 1;
    for (int i = 2; i <= sqrt(1299709); i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= 1299709; j += i) {
                prime[j] = 1;
            }
        }
    }

    int k;
    while (cin >> k && k != 0) {
        if (!prime[k]) {cout << 0 << '\n'; continue;}
        int left = k - 1, right = k + 1;
        while (prime[left]) left--;
        while (prime[right]) right++;
        cout << right - left << '\n';
    }
    return 0;
}
