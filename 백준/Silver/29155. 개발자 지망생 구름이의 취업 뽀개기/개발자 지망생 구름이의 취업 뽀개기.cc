#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N;
vector<int> target;
vector<pii> problem;

bool cmp(pii p1, pii p2) {
    if (p1.first < p2.first) return true;
    else if (p1.first == p2.first) return p1.second < p2.second;

    return false;
}

void Solution() {
    sort(problem.begin(), problem.end(), cmp);

    int ans = 0, level = 1, prev = 0, index = 0;

    while (level <= 5 && index < N) {
        if (target[level - 1] != 0) {
            if (level != problem[index].first) {
                index++;
                continue;
            }

            int t = problem[index].second;
            ans += (t + (prev != 0 ? t - prev : 0));

            prev = t;
            index++;
            target[level - 1]--;
        }

        else if(target[level - 1] == 0) {
            if (level == 5) break;
            ans += 60;
            prev = 0;
            level++;
        }
    }

    cout << ans;
}

void Input() {
    int k, j;
    cin >> N;

    target.resize(5);
    problem.resize(N);

    for (int i = 0; i < 5; i++)
        cin >> target[i];

    for (int i = 0; i < N; i++) {
        cin >> k >> j;
        problem[i] = { k, j };
    }
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