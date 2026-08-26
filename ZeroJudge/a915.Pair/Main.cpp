#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }
    return 0;
}
