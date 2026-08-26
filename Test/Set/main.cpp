#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(2);
    s.insert(-1);

    auto iter = s.find(6);
    //+iter;

    cout << *(++iter);
    return 0;
}
