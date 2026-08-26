#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll powarr[35];
int k;

ll q1(ll lb, ll index) {
    if (lb == powarr[k - 1]) return -1;

    if ((index & lb * 2) == 0) return index + lb;
    else return index - lb;
}

ll q2(ll lb, ll index) {
    if (lb == 1) return -1;

    return index - lb / 2;
}

ll q3(ll lb, ll index) {
    if (lb == 1) return -1;

    return index + lb / 2;
}

ll q4(ll lb, ll index) {
    if (lb == index) return -1;

    return index - 2 * lb;
}

ll q5(ll lb, ll index) {
    ll val = index + 2 * lb;
    if (val > powarr[k]) return -1;

    return val;
}

ll q6(ll lb, ll index) {
    return index * (lb * 2 - 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> k >> q;
    ll twopow = 1;

    for (int i = 0; i < 33; i++) {
        powarr[i] = twopow;
        twopow*=2;
    }

    for (int i = 0; i < q; i++) {
        ll ques, root;
        cin >> ques >> root;

        ll lb = root & -root;
        if (ques == 1) cout << q1(lb, root);
        else if (ques == 2) cout << q2(lb, root);
        else if (ques == 3) cout << q3(lb, root);
        else if (ques == 4) cout << q4(lb, root);
        else if (ques == 5) cout << q5(lb, root);
        else cout << q6(lb, root);

        cout << '\n';
    }
    return 0;
}
