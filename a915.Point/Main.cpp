#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

bool cmb(Point a, Point b) {
    if (a.x < b.x) return true;
    if (a.x == b.x && a.y < b.y) return true;
    return false;
}

Point arr[1000];

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmb);
    for (int i = 0; i < n; i++) {
        cout << arr[i].x << " " << arr[i].y << endl;
    }
}
