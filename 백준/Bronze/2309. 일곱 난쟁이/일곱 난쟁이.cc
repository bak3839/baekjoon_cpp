#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool finish;
vector<int> res;
vector<int> tall;

void Search(int x, int sum) {
    if (res.size() == 7) {
        if (sum == 100) {
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << "\n";
            finish = true;
        }
        return;
    }

    for (int i = x; i < 9; i++) {
        if (sum + tall[i] > 100) return;

        res.push_back(tall[i]);
        Search(i + 1, sum + tall[i]);
        res.pop_back();

        if (finish) return;
    }
}

void Solution() {
    Search(0, 0);
}

void Input() {
    tall.resize(9);

    for (int i = 0; i < 9; i++)
        cin >> tall[i];
    sort(tall.begin(), tall.end());
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
