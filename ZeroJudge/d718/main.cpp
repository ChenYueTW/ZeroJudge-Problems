#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
bool inq[1005];

int main() {
    int n;
    while (cin >> n) {
        fill(arr, arr+1000005, 0);
        fill(inq, inq + 1005, 0);
        vector<queue<int>> v(n);
        for (int i = 0; i < n; i++) {
            int mount;
            cin >> mount;

            for (int j = 0; j < mount; j++) {
                int val;
                cin >> val;
                arr[val] = i + 1;
            }
        }

        string s;
        while (cin >> s) {
            if (s[0] == 'E') {
                int val;
                cin >> val;

                if (inq[arr[val]]) {
                    v[arr[val]].push(val);
                } else {
                    inq[arr[val]] = true;
                    queue<int> qq;
                    qq.push(val);
                    v.push_back(qq);
                }
            }
        }
    }
}
