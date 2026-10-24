#include <bits/stdc++.h>
using namespace std;

bool isMagic(int x) { return x == 10 || x == 20 || x == 30; }

void check(vector<int> &pile, deque<int> &deck, int add) {
    pile.push_back(add);
    bool matched = true;
    while (matched) {
        matched = false;
        int n = pile.size();
        if (n < 3) break;

        int top = pile[n - 1];
        int o1  = pile[n - 2];
        int o2  = pile[n - 3];
        int b1  = pile[0];
        int b2  = pile[1];

        if (isMagic(top + o1 + o2)) {
            deck.push_back(o1);
            deck.push_back(o2);
            deck.push_back(top);
            pile.resize(n - 3);
            matched = true;
            continue;
        }
        if (isMagic(top + o1 + b1)) {
            deck.push_back(o1);
            deck.push_back(b1);
            deck.push_back(top);
            pile.pop_back();
            pile.pop_back();
            pile.erase(pile.begin());
            matched = true;
            continue;
        }
        if (isMagic(top + b1 + b2)) {
            deck.push_back(b2);
            deck.push_back(b1);
            deck.push_back(top);
            pile.pop_back();
            pile.erase(pile.begin(), pile.begin() + 2);
            matched = true;
            continue;
        }
    }
}

int main() {
    int first;
    while (cin >> first) {
        if (first== 0) break;

        vector<int> cards(52);
        cards[0] = first;
        for (int i = 1; i < 52; i++) cin >> cards[i];

        deque<int> deck(cards.begin(), cards.end());
        vector<vector<int>> v(7);
        vector<bool> alive(7, true);
        unordered_set<string> seen;
        int cnt = 7, nxt = 0, plays = 0;

        while(true) {
            if (cnt == 0) {
                cout << "Win: " << plays << '\n';
                break;
            }
            if (deck.empty()) {
                cout << "Loss: " << plays << '\n';
                break;
            }
            while(!alive[nxt]) nxt = (nxt + 1) % 7;
            int card = deck.front();
            deck.pop_front();
            plays++;
            check(v[nxt], deck, card);

            if (v[nxt].empty()) {
                alive[nxt] = 0;
                cnt--;
            }
            ostringstream oss;
            for (int i = 0; i < 7; i++) {
                for (int c : v[i]) oss << c << ',';
                oss << '|';
            }
            for (int c : deck) oss << c << ',';
            oss << '|' << nxt;

            string state = oss.str();
            if (seen.count(state)) {
                cout << "Draw: " << plays << '\n';
                break;
            }
            seen.insert(state);

            nxt = (nxt + 1) % 7;
        }
    }
    return 0;
}
