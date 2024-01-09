#include <iostream>
#include <vector>

using namespace std;

int ans;
vector<int> answer;

void Search(int idx, int prev, int cnt, int sum) {
    if (idx == 10) {
        if (sum >= 5) ans++;
        return;
    }

    for (int i = 1; i <= 5; i++) {
        if (prev == i && cnt >= 2) continue;

        else if (prev == i && cnt < 2) 
            Search(idx + 1, i, cnt + 1, answer[idx] == i ? sum + 1 : sum);
        else
            Search(idx + 1, i, 1, answer[idx] == i ? sum + 1 : sum);
    }
}

void Solution() {
    Search(0, 0, 0, 0);
    cout << ans;
}

void Input() {
    answer.resize(10);

    for (int i = 0; i < 10; i++)
        cin >> answer[i];
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
