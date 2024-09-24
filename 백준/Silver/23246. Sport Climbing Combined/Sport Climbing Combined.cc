#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int num;
    int p;
    int q;
    int r;
}Player;

int N;
vector<Player> players;

bool cmp(Player p1, Player p2) {
    int r1 = p1.p * p1.q * p1.r;
    int r2 = p2.p * p2.q * p2.r;

    int sum1 = p1.p + p1.q + p1.r;
    int sum2 = p2.p + p2.q + p2.r;

    if (r1 < r2) return true;
    else if (r1 == r2) {
        if (sum1 < sum2) return true;
        else if (sum1 == sum2) return p1.num < p2.num;
    }

    return false;
}

void Solution() {
    sort(players.begin(), players.end(), cmp);

    for (int i = 0; i < 3; i++)
        cout << players[i].num << " ";
}

void Input() {
    int num, p, q, r;
    cin >> N;
    
    players.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num >> p >> q >> r;
        players[i] = { num, p, q, r };
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