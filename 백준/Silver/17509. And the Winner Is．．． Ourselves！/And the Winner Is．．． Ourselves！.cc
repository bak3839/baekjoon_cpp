#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0, time = 0;
    vector<pii> p(11);

    for (int i = 0; i < 11; i++) 
        cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());

    for (int i = 0; i < 11; i++) {
        time += p[i].first;
        ans += time + p[i].second * 20; 
    }

    cout << ans;

    return 0;
}
