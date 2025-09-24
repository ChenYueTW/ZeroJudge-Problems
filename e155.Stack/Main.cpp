#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        queue<int> q;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            q.push(i + 1);
        }

        while (n > 1) {
            v.push_back(q.front());
            q.pop();

            q.push(q.front());
            q.pop();

            n--;
        }

        cout << "Discarded cards: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << (i == v.size() - 1 ? "\n": ", ");
        }
        cout << "Remaining card: " << q.front() << endl;
    }
    return 0;
}
