#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, vector<int>> a, pair<string, vector<int>> b) {
    if (a.second[0] == b.second[0]) {
        int gd_a = a.second[4] - a.second[5];
        int gd_b = b.second[4] - b.second[5];
        if (gd_a == gd_b) {
            int in_a = a.second[4];
            int in_b = b.second[4];
            if (in_a == in_b) {
                int total_a = a.second[1] + a.second[2] + a.second[3];
                int total_b = b.second[1] + b.second[2] + b.second[3];
                if (total_a == total_b) {
                    string a_lower = a.first;
                    string b_lower = b.first;
                    transform(a_lower.begin(), a_lower.end(), a_lower.begin(), [](unsigned char c) {
                        return tolower(c);
                    });
                    transform(b_lower.begin(), b_lower.end(), b_lower.begin(), [](unsigned char c) {
                        return tolower(c);
                    });

                    return a_lower < b_lower;
                }
                return total_a > total_b;
            }
            return in_a > in_b;
        }
        return gd_a > gd_b;
    }
    return a.second[0] > b.second[0];
}

void solve() {
    // score-win tie loss-in out
    unordered_map<string, vector<int>> mp;
    int n, race;
    string s;
    getline(cin, s);
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string ss;
        getline(cin, ss);
        mp[ss] = {0, 0, 0, 0, 0, 0};
    }
    cin >> race;
    cin.ignore();
    for (int i = 0; i < race; i++) {
        string team_a, team_b, numstr, line;
        int a_score, b_score;
        getline(cin, line);
        istringstream iss(line);
        getline(iss, team_a, '#');
        getline(iss, numstr, '@');
        a_score = stoi(numstr);
        getline(iss, numstr, '#');
        b_score = stoi(numstr);
        getline(iss, team_b);

        if (a_score > b_score) {
            mp[team_a][0] += 3;
            mp[team_a][1]++;

            mp[team_b][3]++;
        } else if (a_score < b_score) {
            mp[team_b][0] += 3;
            mp[team_b][1]++;

            mp[team_a][3]++;
        } else {
            mp[team_a][0]++;
            mp[team_a][2]++;
            mp[team_b][0]++;
            mp[team_b][2]++;
        }
        mp[team_a][4] += a_score;
        mp[team_a][5] += b_score;
        mp[team_b][4] += b_score;
        mp[team_b][5] += a_score;
    }
    vector<pair<string, vector<int>>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);

    cout << s << '\n';
    for (int i = 0; i < n; i++) {
        int score = v[i].second[0];
        int win = v[i].second[1], tie = v[i].second[2], loss = v[i].second[3];
        int in = v[i].second[4], out = v[i].second[5];
        cout << i + 1 << ") " << v[i].first << " " << score << "p, ";
        cout << win + tie + loss <<"g (" << win << "-" << tie << "-" << loss << "), ";
        cout << in - out << "gd (" << in << "-" << out << ")";
        cout << '\n';
    }
}

int main() {
    //ios::sync_with_stdio(0), cin.tie(0);
    int k;
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; i++) {
        solve();
    }
    return 0;
}
