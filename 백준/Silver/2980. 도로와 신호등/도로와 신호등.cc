#include <iostream>
#include <vector>

using namespace std;
using pipii = pair<int, pair<int, int>>;

int N, L;
vector<pipii> light;

void Solution() {
    int dist = 0, time = 0;

    for (int i = 0; i < N; i++) {
        int R = light[i].second.first;
        int G = light[i].second.second;

        time += light[i].first - dist;
        dist += light[i].first - dist;

        if (time % (R + G) < R) {
            time += R - (time % (R + G));
        }
    }
    time += L - dist;

    cout << time;
}

void Input() {
    int D, R, G;
    cin >> N >> L;

    light.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> D >> R >> G;
        light[i] = { D, {R, G} };
    }
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