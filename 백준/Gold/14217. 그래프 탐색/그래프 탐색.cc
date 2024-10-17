#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, Q;
vector<int> answer;
vector<vector<int>> graph;

void InsertNode(int v1, int v2) {
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

void DeleteNode(int v1, int v2) {
    for(int i = 0; i < graph[v1].size(); i++) {
        int node = graph[v1][i];

        if(node != v2) continue;

        graph[v1].erase(graph[v1].begin() + i);
        break;
    }
}

void SearchGraph() {
    queue<int> q;
    q.push(1);
    answer[1] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];

            if(answer[next] != -1) continue;

            q.push(next);
            answer[next] = answer[node] + 1;
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

void Solution() {
    int n, v1, v2;

    while(Q--) {
        answer.resize(N + 1, -1);
        cin >> n >> v1 >> v2;
        
        if(n == 1) {
            InsertNode(v1, v2);
        } else {
            DeleteNode(v1, v2);
            DeleteNode(v2, v1);
        }

        SearchGraph();
        answer.clear();
    }
}

void Input() {
    int v1, v2;
    cin >> N >> M;

    graph.resize(N + 1);

    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        InsertNode(v1, v2);
    }  

    cin >> Q;
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