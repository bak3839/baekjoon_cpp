#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> ans;
vector<int> pizza;

void Solution() {
    queue<int> q;

    for (int i = 0; i < N; i++)
        q.push(i);

    int t = 1;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        if (--pizza[n] == 0)
            ans[n] = t;

        else q.push(n);

        t++;
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}

void Input() {
    cin >> N;

    ans.resize(N, 0);
    pizza.resize(N);

    for (int i = 0; i < N; i++)
        cin >> pizza[i];
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