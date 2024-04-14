#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> student;

void Solution() {
    int L = 0, R = N - 1, ans = 0;

    while (L < R) {
        if (student[L] + student[R] >= K) {
            L++; R--;
            ans++;
        }

        else L++;
    }

    cout << ans;
}

void Input() {
    cin >> N >> K;

    student.resize(N);

    for (int i = 0; i < N; i++)
        cin >> student[i];
    sort(student.begin(), student.end());
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