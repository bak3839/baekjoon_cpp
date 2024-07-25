#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> node, parent, visit;

void Solution() {
    int root = node[0];
    visit.push_back(root);

    for (int i = 1; i < N; i++) {
        int now = node[i];

        if (parent[now] != -1 || now == root) continue;

        visit.push_back(now);
        parent[now] = node[i - 1];
    }

    sort(visit.begin(), visit.end());

    cout << visit.size() << "\n";

    for (int i = 0; i < visit.size(); i++) 
        cout << parent[visit[i]] << " ";
}

void Input() {
    cin >> N;

    node.resize(N);
    parent.resize(200001, -1);

    for (int i = 0; i < N; i++)
        cin >> node[i];
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