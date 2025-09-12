#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t, remove = 0;
    long score = 0;
    cin >> n >> t;
    vector<int> map(n);
    vector<pair<int, int>> sim(n);

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        map[i] = v;
        sim[i].first = v;
        sim[i].second = i;
    }

    sort(sim.begin(), sim.end(), less<pair<int, int>>());

    while (!map.empty() && remove < sim.size())
    {
        int smallestIndex = sim.at(remove).second;

        if (map.at(smallestIndex) > t) break;

        score += map.at(smallestIndex);

        if (smallestIndex == map.size() - 1) {
            map.at(smallestIndex) = 0;
        } else {
            int nextIndex = smallestIndex + 1;
            while (nextIndex < map.size() && map[nextIndex] == 0)
            {
                nextIndex ++;
            }
            if (nextIndex != smallestIndex) {
                for (int i = 0; i < sim.size(); i++) {
                    if (sim.at(i).first != 0 && sim.at(i).first == map[nextIndex]) {
                        sim.at(i).first += map[smallestIndex];
                        break;
                    }
                }
                map[nextIndex] += map[smallestIndex];
            }
            map.at(smallestIndex) = 0;
        }        
        remove ++;
    }
    
    cout << score;
}
