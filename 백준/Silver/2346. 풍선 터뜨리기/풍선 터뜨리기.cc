#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using pii = pair<int, int>;

int N;
deque<pii> q;

void Solution() {
    while (!q.empty()) {
        pii p = q.front();
        q.pop_front();

        cout << p.first << " ";

        if (p.second < 0) {
            for (int i = 0; !q.empty() && i < p.second * -1; i++) {
                q.push_front(q.back());
                q.pop_back();
            }
        }
        else {
            for (int i = 0; !q.empty() && i < p.second - 1; i++) {
                q.push_back(q.front());
                q.pop_front();
            }
        }
    }
}

void Input() {
    int n;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> n;
        q.push_back({i, n});
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