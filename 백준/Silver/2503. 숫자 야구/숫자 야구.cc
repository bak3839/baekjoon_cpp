#include <bits/stdc++.h>

using namespace std;

typedef struct {
    string q; int s; int b;
}Game;

int N, ans;
bool checked[10];
vector<Game> G;

void Calculate(string q) {
    for (Game g : G) {
        int s = 0, b = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j && g.q[i] == q[j]) s++;
                else if (g.q[i] == q[j]) b++;
            }
        }

        if (g.s != s || g.b != b) return;
    }

    ans++;
}

void Permutation(string q) {
    if (q.size() == 3) {
        Calculate(q);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (checked[i]) continue;

        checked[i] = true;
        Permutation(q + to_string(i));
        checked[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string q;
    int s, b;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> q >> s >> b;
        G.push_back({ q, s, b });
    }
    
    Permutation("");
    cout << ans;
    return 0;
}