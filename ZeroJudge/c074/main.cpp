#include<bits/stdc++.h>
using namespace std;

int arr[14];
vector<int> tmp;
int k;

void c(int step) {
    if (tmp.size() == 6) {
        for (int i = 0; i < 6; i++) cout << tmp[i] << (i == 5 ? "" : " ");
        cout << '\n';
        return;
    }
    for (int i = step; i < k; i++) {
        tmp.push_back(arr[i]);
        c(i + 1);
        tmp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    bool f = 1;
    while (cin >> k) {
        if (k == 0) break;
        if (!f) cout << '\n';
        f = 0;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        c(0);
    }
    return 0;
}
