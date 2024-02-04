#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using psi = pair<string, int>;

bool cmp(psi p1, psi p2) {
    if (p1.second > p2.second) return true;

    else if (p1.second == p2.second) return p1.first > p2.first;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    string s;
    map<string, int> m;
    

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        m[s]++;
    }
   
    vector<psi> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    cout << v[0].first << " " << v[0].second;
    return 0;
}
