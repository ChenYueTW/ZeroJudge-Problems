#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num = 1;
    while (cin >> n) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            string s, e, non;
            cin >> s >> e;
            getline(cin, non);
            istringstream ss(s);
            istringstream se(e);
            string hour, minute;
            getline(ss, hour, ':');
            getline(ss, minute);
            int start_time = stoi(hour) * 60 + stoi(minute);
            getline(se, hour, ':');
            getline(se, minute);
            int end_time = stoi(hour) * 60 + stoi(minute);
            v.push_back({start_time, end_time});
        }
        sort(v.begin(), v.end());
        int ans = -1, start = -1;
        for (int i = 0; i < n - 1; i++) {
            int val = v[i + 1].first - v[i].second;
            if (ans < val) {
                ans = val;
                start = v[i].second;
            }
        }
        if (ans <= v[0].first - 600) {
            ans = v[0].first - 600;
            start = 600;
        }
        if (ans < 1080 - v.back().second) {
            ans = 1080 - v.back().second;
            start = v.back().second;
        }

        int hour = ans / 60, minute = ans % 60;
        int start_hour = start / 60, start_min = start % 60;
        cout << "Day #" << num << ": the longest nap starts at " << start_hour << ":" << (start_min < 10 ? "0" : "") << start_min;
        cout << " and will last for ";
        if (hour == 0) cout << minute << " minutes." << '\n';
        else cout << hour << " hours and " << minute << " minutes." << '\n';
        num++;
    }
    return 0;
}
