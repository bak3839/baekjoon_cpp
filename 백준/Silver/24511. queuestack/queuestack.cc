#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct {
    int type;
    int num;
}Data;

int N, M;
vector<int> A;
deque<int> dq;

void Solution() {
    vector<int> res;
    int n;
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> n;

        dq.push_front(n);
        res.push_back(dq.back());
        dq.pop_back();
    }

    for (auto r : res)
        cout << r << " ";
}

void Input() {
    int n;
    cin >> N;

    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++) {
        cin >> n;

        if (A[i] == 1) continue;
        dq.push_back(n);
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