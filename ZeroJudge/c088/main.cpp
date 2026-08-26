#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s, a, b;
    while (getline(cin, s)) {
        if (s == "0") break;
        map<int, int, greater<int>> ans;
        int num = 1;
        istringstream ss(s);
        while (ss >> a >> b ) {
            //cout << stoi(a) << " " << stoi(b) << '\n';
            num *= round(pow(stoi(a), stoi(b)));
            //cout << num << '\n';
        }
        num--;
        //cout << num;

        for (int i = 2; i <= sqrt(num); i++) {
            while(num % i == 0) {
                num /= i;
                ans[i]++;
            }
        }
        if (num != 1) ans[num]++;
        for (auto it = ans.begin(); it != ans.end(); it++) {
            cout << (it == ans.begin() ? "" : " ") << it -> first << " " << it -> second;
        }
        cout << '\n';
    }
    return 0;
}
