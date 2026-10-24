#include<bits/stdc++.h>
using namespace std;

vector<int> v(3);

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int c = 2;
    for (int i = 0; i < 3; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = n; i > 0; i--)
        if (c < 0 || i != v[c]) cout << "No. " << i << '\n';
        else c--;
    return 0;
}