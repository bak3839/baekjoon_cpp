#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, M;
bool ans = false;
vector<bool> status;
vector<pii> form;

void Calculate() {
    for (int i = 0; i < M; i++) {
        bool b1, b2;
        int n1 = form[i].first;
        int n2 = form[i].second;

        if (n1 < 0) b1 = !status[n1 * -1];
        else b1 = status[n1];

        if (n2 < 0) b2 = !status[n2 * -1];
        else b2 = status[n2];

        if (!(b1 || b2)) return;
    }

    ans = true;
}

void Search(int x) {
    if (x > N) {
        Calculate();
        return;
    }

    for (int i = 0; i <= 1; i++) {
        status[x] = i == 0 ? false : true;
        Search(x + 1);

        if (ans) return;
    }
}

void Solution() {
    Search(1);

    if (ans) cout << 1;
    else cout << 0;
}

void Input() {
    cin >> N >> M;

    form.resize(M);
    status.resize(N + 1, false);

    for (int i = 0; i < M; i++) 
        cin >> form[i].first >> form[i].second;
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
