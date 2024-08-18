#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int R, C;
vector<string> line;

void Solution() {
    vector<pii> res;
    vector<int> ans(9);

    for (int i = 0; i < R; i++) {
        int index = C - 1;
        char now = line[i][index];

        while (1) {
            if (now == 'S') break;

            else if ('1' <= now && now <= '9') {
                res.push_back({ index, now - '0' });
                break;
            }

            now = line[i][--index];
        }
    }

    sort(res.begin(), res.end(), greater<pii>());

    int grade = 0, prev = 0;

    for (int i = 0; i < res.size(); i++) {
        int index = res[i].first, num = res[i].second - 1;

        if (prev != index) {
            prev = index;
            grade++;
        }

        ans[num] = grade;
    }
    
    for (int i = 0; i < 9; i++)
        cout << ans[i] << "\n";
}

void Input() {
    cin >> R >> C;

    line.resize(R);

    for (int i = 0; i < R; i++)
        cin >> line[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}