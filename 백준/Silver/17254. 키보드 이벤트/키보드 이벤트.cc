#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int a;
    int b;
    char ch;
}KeyBoard;

int N, M;
vector<KeyBoard> flow;

bool cmp(KeyBoard k1, KeyBoard k2) {
    if (k1.b < k2.b) return true;
    else if (k1.b == k2.b) return k1.a < k2.a;

    return false;
}

void Solution() {
    sort(flow.begin(), flow.end(), cmp);

    for (int i = 0; i < M; i++)
        cout << flow[i].ch;
}

void Input() {
    cin >> N >> M;

    flow.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> flow[i].a >> flow[i].b >> flow[i].ch;
    }
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