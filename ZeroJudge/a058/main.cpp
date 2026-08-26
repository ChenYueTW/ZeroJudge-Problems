#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 0, b = 0, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (v % 3 == 0) a++;
        else if (v % 3 == 1) b++;
        else c++;
    }
    cout << a << " " << b << " " << c;
    return 0;
}