#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> d(1001, 2000000002); // 최단 거리 테이블 만들기
vector<vector<pair<int, int>>> graph(1001, vector<pair<int, int>>(1001));

void dijkstra(int start, int end){
    priority_queue<pair<int, int>> pq; // 거리, 노드 인덱스
    bool pass = false;

    pq.push({ 0,start }); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first; //현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();

        //if (d[now] < dist && now == end) break;

        if (d[now] < dist) continue; // 이미 최단경로를 체크한 노드인 경우 패스  

        for (int i = 0; i < graph[now].size(); i++) // 해당 노드에서 연결된 노드들을 우선순위 큐에 삽입
        {
            int cost = dist + graph[now][i].second; // 거쳐서 가는 노드의 비용을 계산
                                                   // 현재노드까지 비용 + 다음 노드 비용

            if (cost < d[graph[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[graph[now][i].first] = cost;
                pq.push({ -cost, graph[now][i].first });
                if (graph[now][i].first == end) {
                    pass = true;
                    break;
                }
            }
        }
        if(pass) break;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, M, start, end, cost;;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
    }

    cin >> start >> end;

    dijkstra(start, end);

    cout << d[end];

	return 0;
}