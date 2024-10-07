#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using psi = pair<string, int>;
int N;

void Solution() {
    map<string, int> m;

    string name, ans = "Not Delicious...";
    bool pass = false;
    int x;

    for (int i = 0; i < N; i++) {
        cin >> name >> x;
        m[name] += x;
    }

    vector<psi> res(m.begin(), m.end());

    for (int i = 0; i < res.size() - 1; i++) {
        
        int a1 = res[i].second, a2;

        for (int j = i + 1; j < res.size(); j++) {
            a2 = res[j].second;

            if (a1 < a2) pass = (floor(a1 * 1.618) == a2);
            else pass = (floor(a2 * 1.618) == a1);

            if (pass) {
                ans = "Delicious!";
                break;
            }
        }

        if (pass) break;
    }

    cout << ans;
}

void Input() {
    cin >> N;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}