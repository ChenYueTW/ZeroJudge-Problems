#include <bits/stdc++.h>
using namespace std;

struct Note {
    int time, left, right, id;
};
struct cli {
    int time, loc;
};
Note music[50005];
cli click[50005];

bool cmp1(Note a, Note b) {
    return a.time < b.time;
}

bool cmp2(cli a, cli b) {
    return a.time < b.time;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int nt, l, r;
        cin >> nt >> l >> r;
        music[i].time = nt;
        music[i].left = l;
        music[i].right = r;
        music[i].id = i;
    }
    for (int i = 0; i < m; i++) {
        int ct, x;
        cin >> ct >> x;
        click[i].time = ct;
        click[i].loc = x;
    }
    sort(music, music + n, cmp1);
    sort(click, click + n, cmp2);

    int index = 0;
    for (int i = 0; i < m; i++) {
        if (abs(click[index].time - music[i].time) <= 90 && click[i].loc >= music[i].left && click[i].loc <= music[i].right) {
            cout << music[index].id + 1 << " ";
            if (abs(click[index].time - music[i].time) <= 40) cout << "Perfact";
            else if (abs(click[index].time - music[i].time) <= 75) cout << "Good";
            else cout << "Bad";
            index++;
        } else {
            cout << "Miss";
        }
        if (i != m - 1) cout << '\n';
    }
    return 0;
}