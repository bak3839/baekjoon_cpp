#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> want;
deque<int> q;
int cnt;

void left(int target) {
    while (1) {
        if (q.front() == target) {
            q.pop_front();
            break;
        }
        else {
            cnt++;
            q.push_back(q.front());
            q.pop_front();
        }
    }
}

void right(int target) {
    while (1) {
        if (q.front() == target) {
            q.pop_front();
            break;
        }
        else {
            cnt++;
            q.push_front(q.back());
            q.pop_back();
        }
    }
}

void Solution(int N, int M) {
    int n = M - 1;
    while (M--) {
        bool pass = false;

        int size = q.size() / 2;
        int target = want[n - M];

        if (q.size() % 2) size += 1;

        for (int i = size; i < q.size(); i++) {
            if (target == q[i]) pass = true;
        }

        if (pass) right(target);
        else left(target);
    }
    cout << cnt;
}

void Input() {
    int N, M;
    cin >> N >> M;
    want.resize(M);

    for (int i = 1; i <= N; i++) q.push_back(i);
    for (int i = 0; i < M; i++) cin >> want[i];

    Solution(N, M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();

    return 0;
}