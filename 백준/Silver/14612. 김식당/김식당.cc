#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<pii> order;

bool cmp(pii p1, pii p2) {
    if (p1.second < p2.second) return true;
    else if (p1.second == p2.second) return p1.first < p2.first;
    return false;
}

void Solution() {
    int t, n, count = 0;
    string option;

    for (int i = 0; i < N; i++) {
        cin >> option;

        if (option == "order") {
            cin >> n >> t;
            count++;
            order.push_back({ n, t });
        }

        else if (option == "sort") {
            sort(order.begin(), order.end(), cmp);
        }

        else {
            cin >> n;

            for (vector<pii>::iterator iter = order.begin(); iter != order.end(); iter++) {
                if (n == iter->first) { 
                    order.erase(iter);
                    break; 
                } 
            }
        }

        for (int j = 0; j < order.size(); j++) {
            n = order[j].first;
            cout << n << " ";
        }

        if (order.empty()) cout << "sleep";
        cout << "\n";
    }
}

void Input() {
    cin >> N >> M;
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