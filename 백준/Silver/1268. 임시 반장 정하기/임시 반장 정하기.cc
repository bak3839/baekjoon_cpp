#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> student;

void Solution() {
    int ans = 1, cnt = 0, res = 0;

    for (int i = 0; i < N; i++) {
        cnt = 0;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            for (int k = 0; k < 5; k++) {
                if (student[i][k] == student[j][k]) {
                    cnt++;
                    break;
                }
            }
        }

        if (cnt > res) {
            res = cnt;
            ans = i + 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    student.resize(N, vector<int>(5));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++)
            cin >> student[i][j];
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}