#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N, M;

vector<int> Rank(100001, 0);
priority_queue<pii> max_pq;
priority_queue<pii, vector<pii>, greater<pii>> min_pq;

void Solution() { 
    int P, L, x;
    string mode;
    map<pii, bool> m;
    
    while (M--) {
        cin >> mode;

        if (mode == "add") {
            cin >> P >> L;

            Rank[P] = L;
            max_pq.push({ L, P });
            min_pq.push({ L, P });
        }

        else if (mode == "solved") {
            cin >> P;
            m[{P, Rank[P]}] = true;
        }

        else {
            cin >> x;

            if (x == 1) {
                while (!max_pq.empty()) {
                    L = max_pq.top().first;
                    P = max_pq.top().second;

                    if (m.find({ P, L }) == m.end()) {
                        cout << P << "\n";
                        break;
                    }

                    max_pq.pop();
                }
            }
            else {
                while (!min_pq.empty()) {
                    L = min_pq.top().first;
                    P = min_pq.top().second;

                    if (m.find({ P, L }) == m.end()) {
                        cout << P << "\n";
                        break;
                    }

                    min_pq.pop();
                }
            }

        }
    }
}

void Input() {
    int P, L;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P >> L;

        Rank[P] = L;
        max_pq.push({ L, P });
        min_pq.push({ L, P });
    }

    cin >> M;
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