#include<bits/stdc++.h>
using namespace std;

int mp[8][8];
pair<int, int> nxt[] = {{1, 0}, {-1 ,0}, {0, 1}, {0, -1}};
pair<int, int> bisnxt[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
pair<int, int> knightnxt[] = {{2, -1}, {2, 1}, {-2, -1}, {-2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

bool pawn(bool is_upper, int i, int j) {
    if (is_upper) {
        int ci = i - 1, cj = j - 1;
        if (ci >= 0 && ci < 8 && cj >= 0 && cj < 8) {
            if (mp[ci][cj] == 6) return true;
        }
        cj = j + 1;
        if (ci >= 0 && ci < 8 && cj >= 0 && cj < 8) {
            if (mp[ci][cj] == 6) return true;
        }
    } else {
        int ci = i + 1, cj = j - 1;
        if (ci >= 0 && ci < 8 && cj >= 0 && cj < 8) {
            if (mp[ci][cj] == -6) return true;
        }
        cj = j + 1;
        if (ci >= 0 && ci < 8 && cj >= 0 && cj < 8) {
            if (mp[ci][cj] == -6) return true;
        }
    }
    return false;
}

bool rook(bool is_upper, int i, int j) {
    int ci = i, cj = j;
    for (int n = 0; n < 4; n++) {
        while (true) {
            ci += nxt[n].first, cj += nxt[n].second;
            if (ci < 0 || ci > 7 || cj < 0 || cj > 7) break;
            int val = mp[ci][cj];
            if (val == (is_upper ? 6 : -6)) return true;
            if (val != 0) break;
        }
        ci = i, cj = j;
    }
    return 0;
}

bool bishop(bool is_upper, int i, int j) {
    for (int n = 0; n < 4; n++) {
        int ci = i, cj = j;
        while (true) {
            ci += bisnxt[n].first, cj += bisnxt[n].second;
            if (ci < 0 || ci > 7 || cj < 0 || cj > 7) break;
            int val = mp[ci][cj];
            if (val == (is_upper ? 6 : -6)) return true;
            if (val != 0) break;
        }
        ci = i, cj = j;
    }
    return 0;
}

bool knight(bool is_upper, int i, int j) {
    for (int n = 0; n < 8; n++) {
        int ci = i + knightnxt[n].first, cj = j + knightnxt[n].second;
        if (ci < 0 || ci > 7 || cj < 0 || cj > 7) continue;
        if (is_upper && mp[ci][cj] == 6) return true;
        if (!is_upper && mp[ci][cj] == -6) return true;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    int id = 1;
    while (true) {
        bool f = 0;
        unordered_map<int, vector<pair<int, int>>> white, black;
        for (int i = 0; i < 8; i++) {
            cin >> s;
            if (s != "........") f = 1;

            for (int j = 0; j < 8; j++) {
                switch (s[j]) {
                    case '.':
                        mp[i][j] = 0;
                        break;
                    case 'p':
                        mp[i][j] = 1;
                        black[1].push_back({i, j});
                        break;
                    case 'P':
                        mp[i][j] = -1;
                        white[1].push_back({i, j});
                        break;
                    case 'n':
                        mp[i][j] = 2;
                        black[2].push_back({i, j});
                        break;
                    case 'N':
                        mp[i][j] = -2;
                        white[2].push_back({i, j});
                        break;
                    case 'b':
                        mp[i][j] = 3;
                        black[3].push_back({i, j});
                        break;
                    case 'B':
                        mp[i][j] = -3;
                        white[3].push_back({i, j});
                        break;
                    case 'r':
                        mp[i][j] = 4;
                        black[4].push_back({i, j});
                        break;
                    case 'R':
                        mp[i][j] = -4;
                        white[4].push_back({i, j});
                        break;
                    case 'q':
                        mp[i][j] = 5;
                        black[5].push_back({i, j});
                        break;
                    case 'Q':
                        mp[i][j] = -5;
                        white[5].push_back({i, j});
                        break;
                    case 'k':
                        mp[i][j] = 6;
                        black[6].push_back({i, j});
                        break;
                    case 'K':
                        mp[i][j] = -6;
                        white[6].push_back({i, j});
                        break;
                    default:
                        break;
                }
            }
        }
        if (!f) break;
        // check white is check?
        bool check = 0;
        for (int i = 1; i <= 6; i++) {
            vector<pair<int, int>> v = black[i];
            for (pair<int, int> p : v) {
                if (i == 1) check = pawn(0, p.first, p.second);
                else if (i == 2) check = knight(0, p.first, p.second);
                else if (i == 3) check = bishop(0, p.first, p.second);
                else if (i == 4) check = rook(0, p.first, p.second);
                else if (i == 5) check = bishop(0, p.first, p.second) || rook(0, p.first, p.second);
                if (check) break;
            }
            if (check) break;
        }
        if (check) {
            printf("Game #%d: white king is in check.\n", id);
            id++;
            continue;
        }
        for (int i = 1; i <= 6; i++) {
            vector<pair<int, int>> v = white[i];
            for (pair<int, int> p : v) {
                if (i == 1) check = pawn(1, p.first, p.second);
                else if (i == 2) check = knight(1, p.first, p.second);
                else if (i == 3) check = bishop(1, p.first, p.second);
                else if (i == 4) check = rook(1, p.first, p.second);
                else if (i == 5) check = bishop(1, p.first, p.second) || rook(0, p.first, p.second);
                if (check) break;
            }
            if (check) break;
        }
        if (check) {
            printf("Game #%d: black king is in check.\n", id);
            id++;
            continue;
        } else {
            printf("Game #%d: no king is in check.\n", id);
            id++;
        }
    }
}
