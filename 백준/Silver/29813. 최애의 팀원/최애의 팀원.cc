#include <iostream>
#include <vector>
#include <queue>


using namespace std;
using psi = pair<string, int>;

int N;
queue<int> q;
vector<psi> student;

void Solution() {
    while (q.size() > 1) {
        int n = q.front();
        q.pop();

        int pass = student[n].second;

        while (--pass) {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }

    cout << student[q.front()].first;
}

void Input() {
    cin >> N;

    student.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> student[i].first >> student[i].second;
        q.push(i);
    }   
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