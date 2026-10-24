#include<bits/stdc++.h>
using namespace std;

map<int, int> m;
vector<deque<int>> v[1000];

int main() {
    int n, scenario = 1;
    while (cin >> n && n != 0) {
        cout << "Scenario #" << scenario << '\n';
        for (int i = 0; i < n; i++) {
            m[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            deque<int> cache;
            for (int j = 0; j < num; j++) {
                int val; cin >> val;
                v[i].push_back(val);
                m[val] = i;
            }
        }
        string s;
        while (cin >> s) {
            if (s == "ENQUEUE") {
                int num; cin >> num;
                int r = m[num];
                if (r == -1) {
                    m[num] = n - 1;
                    v[n - 1].d.push_back(num);
                } else {
                    auto iter = find(v[r].begin(), v[r].end(), num);
                    v[r].erase(iter);
                    v[r].push_back(num);
                }
            } else if (s == "DEQUEUE") {
                int index = 0;
                while (v[index].d.empty()) index++;
                int num = v[index].d.front();
                v[index].d.pop_front();
                m[num] = -1;
                cout << num << '\n';
            } else break;
        }
        cout << '\n';
        scenario++;
    }
    return 0;
}