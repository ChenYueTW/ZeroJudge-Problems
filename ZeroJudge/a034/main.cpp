#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    while (cin >> n) {
        int index = 0;
        ll temp = 1;
        while (temp <= n) {
            index++;
            temp *= 2;
        }
        index--;
        while(index != 0) {
            if (n >= round(pow(2, index))) {
                n -= round(pow(2, index));
                cout << 1;
            } else {
                cout << 0;
            }
            index --;
        }
        cout << n << '\n';
    }
    return 0;
}
