#include <bits/stdc++.h>
using namespace std;

int arr[10005];

void bst(int l, int r) {
    if (l > r) return;
    int root = arr[l];
    int nextIndex = r + 1;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] > root) {
            nextIndex = i;
            break;
        }
    }

    bst(l + 1, nextIndex - 1);
    bst(nextIndex, r);
    cout << root << '\n';
}

int main() {
    int n, cnt = 0;
    while (cin >> n) {
        arr[cnt ] = n;
        cnt++;
    }

    bst(0, cnt - 1);
    return 0;
}
