#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        while (true) {
            stack<int> A, S;
            vector<int> goal(n);
            int p = 0;
            for (int i = 0; i < n; i++) {
                cin >> goal[i];
                if (goal[i] == 0) break;
                A.push(n - i);
            }
            if (goal[0] == 0) break;

            bool ended = false;
            while (true) {
                ended = false;
                if (!S.empty() && goal[p] == S.top()) {
                    p++;
                    S.pop();
                    ended = true;
                }
                if (!A.empty() && !ended) {
                    int v = A.top();
                    A.pop();
                    S.push(v);
                    ended = true;
                }
                if (!ended) {
                    break;
                }
            }
            cout << (A.empty() && S.empty() ? "Yes" : "No") << endl;
        }
        cout << '\n';
    }
    return 0;
}
