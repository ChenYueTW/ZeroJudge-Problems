#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

pair<int, int> dfs(int v) {
    int last = 0;
    stack<int> nums;
    stack<string> oper;

    for (int i = v; i < vec.size(); i++) {
        if (vec[i] == "(") {
            pair<int, int> p = dfs(i + 1);
            nums.push(p.first);
            i = p.second;
            continue;
        } else if (vec[i] == ")") {
            last = i;
            break;
        }
        if (vec[i] == "+") oper.push("+");
        else if (vec[i] == "-") oper.push("-");
        else if (vec[i] == "*") oper.push("*");
        else if (vec[i] == "/") oper.push("/");
        else if (vec[i] == "%") oper.push("%");
        else nums.push(stoi(vec[i]));

        if (oper.empty()) continue;
        string op = oper.top();
        if (op == "*" || op == "/" || op == "%") {
            int a = nums.top();
            nums.pop();
            int b;
            if (vec[i + 1] == "(") {
                pair<int, int> p = dfs(i + 2);
                b = p.first;
                i = p.second - 1;
            } else {
                b = stoi(vec[i + 1]);
            }

            if (op == "*") nums.push(a * b);
            else if (op == "/") nums.push(a / b);
            else if (op == "%") nums.push(a % b);
            i++;
            oper.pop();
        }
    }

    stack<int> newnums;
    stack<string> newoper;
    while (!nums.empty()) {
        newnums.push(nums.top());
        nums.pop();
    }
    while (!oper.empty()) {
        newoper.push(oper.top());
        oper.pop();
    }
    while(!newnums.empty() && !newoper.empty()) {
        int a = newnums.top(); newnums.pop();
        int b = newnums.top(); newnums.pop();
        string op = newoper.top(); newoper.pop();

        if (op == "-") {
            newnums.push(a - b);
        } else if (op == "*") {
            newnums.push(a * b);
        } else if (op == "/") {
            newnums.push(a / b);
        } else if (op == "%") {
            newnums.push(a % b);
        } else {
            newnums.push(a + b);
        }
    }
    return {newnums.top(), last};
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        string token;
        while (ss >> token) vec.push_back(token);

        cout << dfs(0).first << '\n';
        vec = vector<string>();
    }
    return 0;
}
