#include <iostream>
#include <vector>

using namespace std;

int m[6] = { 5, 3, 4, 1, 2, 0 };
vector<vector<int>> dice;
vector<int> choice;
int N, ans;

void Calculate() {
    int res = 0;

    for (int i = 0; i < N; i++) {
        int d = choice[i];
        int u = m[d];
        int n = 0;

        for (int j = 0; j < 6; j++) {
            if (j == u || j == d) continue;

            n = max(n, dice[i][j]);
        }
        res += n;
    }

    ans = max(ans, res);
}

void Search(int num, int cnt) {
    if (cnt == N) {
        Calculate();
        return;
    }

    int index;

    for (int i = 0; i < 6; i++) {
        if (num == dice[cnt][i]) {
            index = i;
            break;
        }
    }

    choice.push_back(index);
    Search(dice[cnt][m[index]], cnt + 1);
    choice.pop_back();
}

void Solution() {
    for (int i = 0; i < 6; i++) {
        choice.push_back(i);
        Search(dice[0][m[i]], 1);
        choice.pop_back();
    }

    cout << ans;
}

void Input() {
    cin >> N;

    dice.resize(N, vector<int>(6));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++)
            cin >> dice[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
