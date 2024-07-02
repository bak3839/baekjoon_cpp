#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N, L, K;
vector<bool> done;
vector<pii> easy;
vector<pii> hard;

bool cmp(pii p1, pii p2) {
    return p1.second < p2.second;
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (hard[i].second > L || K == 0) break;

        K--;
        ans += 140;
        done[hard[i].first] = true;
    }

    for (int i = 0; i < N; i++) {
        if (easy[i].second > L || K == 0) break;
        if (done[easy[i].first]) continue;

        K--;
        ans += 100;
    }

    cout << ans;
}

void Input() {
    cin >> N >> L >> K;

    easy.resize(N);
    hard.resize(N);
    done.resize(N, false);
   
    for (int i = 0; i < N; i++) {
        cin >> easy[i].second >> hard[i].second;

        easy[i].first = i;
        hard[i].first = i;
    }
        

    sort(easy.begin(), easy.end(), cmp);
    sort(hard.begin(), hard.end(), cmp);
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