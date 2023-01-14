#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int res, N, K;
vector<pair<bool, int>> visited;

void bfs(int x) {
   int next[3];
   queue<pair<int, int>> q;
   q.push({ x, 0 });
   visited[x] = { true, 0 };

   while (!q.empty()) {
      int now = q.front().first;
      int cnt = q.front().second;
      q.pop();

      if (now == K && res > cnt) res = cnt;

      else {
         next[0] = now + 1;
         next[1] = now - 1;
         next[2] = now * 2;

         for (int i = 0; i < 3; i++) {
            if (next[i] < 0 || next[i] > K + 1 || next[i] > 100001) continue;

            if (!visited[next[i]].first) {
               q.push({ next[i], cnt + 1 });
               visited[next[i]].first = true;
               visited[next[i]].second = cnt + 1;
            }

            else if (visited[next[i]].first && visited[next[i]].second >= cnt + 1) {
               q.push({ next[i], cnt + 1 });
               visited[next[i]].second = cnt + 1;
            }
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   cin >> N >> K;

   if (N == K) cout << 0;

   else if (N > K) cout << N - K;

   else {
      res = K - N;
      visited.resize(K + 2, { false, res });
      bfs(N);
      cout << res;
   }

   return 0;
}