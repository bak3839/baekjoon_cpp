#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

vector<bool> visit;
int F, S, G, U, D;

void Solution() {
    int ans = -1;
    queue<pii> q;
    q.push({S, 0});
    visit[S] = true;

    if (S > G && D == 0) {
        cout << "use the stairs";
        return;
    }

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now > F || now <= 0) continue;

        if (now == G) {
            ans = cnt;
            break;
        }     

        int up = now + U;
        int down = now - D;

        if (up <= F && up > 0 && !visit[up]) {
            q.push({ up, cnt + 1 });
            visit[up] = true;
        }
        if (down <= F && down > 0 && !visit[down]) {
            q.push({ down, cnt + 1 });
            visit[down] = true;
        }
    }

    if(ans == -1) cout << "use the stairs";
    else cout << ans;
}

void Input() {
    cin >> F >> S >> G >> U >> D;
    visit.resize(F + 1, false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}