#include <iostream>
#include <vector>

using namespace std;

int T, K, W, L;
int mv[2][3] = { {-1, 6, 2}, {1, 2, 6} }; // 방향, 내 톱니, 옆 톱니

vector<int> counts;
vector<bool> visited;
vector<string> wheels;

// 톱니바퀴 회전 수 만큼 반영하여 극 반환
char Pole(int w, int n) {
    int spin = n - (counts[w] % 8);

    if (spin < 0) spin += 8;
    else if (spin >= 8) spin -= 8;

    return wheels[w][spin];
}

// 톱니바퀴 회전 전파
void SpinWheel(int w, int l) {
    int next;
    char my, other;

    visited[w] = true;

    for (int i = 0; i < 2; i++) {
        next = w + mv[i][0];

        if (next < 0 || next >= T || visited[next]) continue;

        my = Pole(w, mv[i][1]);
        other = Pole(next, mv[i][2]);

        if (my != other) SpinWheel(next, (l == 1 ? -1 : 1));
    }

    counts[w] += l;
    visited[w] = false;
}

void Solution() {
    int ans = 0;
    cin >> K;

    while (K--) {
        cin >> W >> L;
        SpinWheel(W - 1, L);
    }

    for (int i = 0; i < T; i++) {
        if (Pole(i, 0) == '1') ans++;
    }

    cout << ans;
}

void Input() {
    cin >> T;

    wheels.resize(T);
    counts.resize(T, 0);
    visited.resize(T, false);

    for (int i = 0; i < T; i++)
        cin >> wheels[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}