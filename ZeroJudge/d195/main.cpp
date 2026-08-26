#include<bits/stdc++.h>
using namespace std;

int arr[100005];
int n, ans;

void conquer(int l, int r, int mid) {
    int i = l, left = l, right = mid + 1;
    int tmp[n];

    while (left <= mid && right <= r) {
        if (arr[left] < arr[right]) {tmp[i] = arr[left]; left++;}
        else {tmp[i] = arr[right]; right++; ans += (mid - left + 1);}
        i++;
    }
    while (left <= mid) {
        tmp[i] = arr[left];
        left++;
        i++;
    }
    while (right <= r) {
        tmp[i] = arr[right];
        right++;
        i++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i];
    }
}

void divide(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    divide(l, mid);
    divide(mid + 1, r);
    conquer(l, r, mid);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        ans = 0;
        divide(0, n - 1);
        cout << (ans % 2 == 0 ? "Carlos" : "Marcelo") << '\n';
    }
    return 0;
}
