#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<int> point;
vector<pii> student;

bool cmp(pii p1, pii p2) {
    if (p1.second > p2.second) return true;
    else if (p1.second == p2.second) return p1.first < p2.first;
    return false;
}

void Solution() {
    int num;
    char ch;

    for (int i = 0; i < M; i++) {
        int res = 0;
        cin >> num;

        for (int j = 0; j < N; j++) {
            cin >> ch;

            if (ch == 'X') continue;

            res += point[j];
        }

        student[i] = { num, res };
    }

    sort(student.begin(), student.end(), cmp);

    cout << student[0].first << " " << student[0].second;
}

void Input() {
    cin >> N >> M;

    point.resize(N);
    student.resize(M);

    for (int i = 0; i < N; i++)
        cin >> point[i];
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