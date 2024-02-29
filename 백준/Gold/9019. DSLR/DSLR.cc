#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
using pis = pair<int, string>;

int start, target;
vector<bool> visit;

void Solution() {
    string ans;
    queue<pis> q;
    q.push({ start, "" });
    visit[start] = true;

    while (!q.empty()) {
        if (q.front().first == target) {
            ans = q.front().second;
            break;
        }

        int now = q.front().first;
        string cmd = q.front().second;
        q.pop();

        if (now == 0) {
            if (!visit[9999]) {
                visit[9999] = true;
                q.push({ 9999, cmd + "S" });
            }
            continue;
        }
        
        if (now * 2 > 9999) {
            if (now * 2 == 10000 && target == 10000) {
                ans = cmd + "D";
                break;
            }

            if (!visit[now * 2 % 10000]) {
                visit[now * 2 % 10000] = true;
                q.push({ now * 2 % 10000, cmd + "D" });               
            }           
        }
        else {
            if (!visit[now * 2]) {
                visit[now * 2] = true;
                q.push({ now * 2, cmd + "D" });
            }
        }

        if (!visit[now - 1]) {
            visit[now - 1] = true;
            q.push({ now - 1, cmd + "S" });
        }
        
        int numL = (now % 1000) * 10 + (now / 1000), numR = now / 10 + (now % 10) * 1000;

        if (!visit[numL]) {
            visit[numL] = true;
            q.push({ numL, cmd + "L" });
        }

        if (!visit[numR]) {
            visit[numR] = true;
            q.push({ numR, cmd + "R" });
        }
    }

    cout << ans << "\n";
}

void Input() {
    cin >> start >> target;
    visit.resize(10001, false);
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        visit.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
