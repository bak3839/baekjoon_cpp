#include <iostream>
#include <queue>

using namespace std;

int N, K;
vector<int> graph;

void Solution() {
    int now = 0, cnt = 0;

    while (now != K) {
        int n = graph[now];
        graph[now] = -1;
        now = n;

        cnt++;

        if (graph[now] == -1) {
            cnt = -1;
            break;
        }
    }

    cout << cnt;
}

void Input() {
    cin >> N >> K;

    graph.resize(N);

    for (int i = 0; i < N; i++)
        cin >> graph[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}