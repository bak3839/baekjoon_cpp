#include <iostream>
#include <vector>

using namespace std;

int N, ans_max = -1000000001, ans_min = 1000000001;
int oper[4];
vector<int> num;

void Search(int sum, int index) {
    if (index == N) {
        ans_max = max(ans_max, sum);
        ans_min = min(ans_min, sum);
        return;
    }

    for (int i = 0;i < 4;i++) {
        if (oper[i] == 0) continue;

        int res = 0;

        if (i == 0) res = sum + num[index];
        else if(i == 1) res = sum - num[index];
        else if(i == 2) res = sum * num[index];
        else res = sum / num[index];

        oper[i]--;
        Search(res, index + 1);
        oper[i]++;
    }
}

void Solution() {
    Search(num[0], 1);
    cout << ans_max << "\n" << ans_min;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0;i < N;i++)
        cin >> num[i];

    for (int i = 0;i < 4;i++)
        cin >> oper[i];
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
