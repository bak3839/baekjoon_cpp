#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

void Solution() {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();

        if (q.empty()) break;

        q.push(q.front());
        q.pop();
    }
}

void Input() {
    cin >> N;

    for (int i = 1; i <= N; i++)
        q.push(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}