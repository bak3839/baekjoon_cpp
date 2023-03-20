#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<pair<int, int>> egg;

void solve(int idx) {   
    if (idx == N) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (egg[i].first <= 0) cnt++;
        }
        ans = max(cnt, ans);
        return;
    }

    if (egg[idx].first <= 0) solve(idx + 1);

    else {
        bool pass = false;
        int w1, w2;
        for (int i = 0; i < N; i++) {
            if (egg[i].first <= 0 || idx == i) continue;

            w1 = egg[idx].second;
            w2 = egg[i].second;

            egg[idx].first -= w2;
            egg[i].first -= w1;  
           
            pass = true;
            solve(idx + 1);
    
            egg[idx].first += w2;
            egg[i].first += w1;
        }
        if (!pass) solve(N);
    }       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    egg.resize(N);

    for (int i = 0; i < N; i++) cin >> egg[i].first >> egg[i].second;

    solve(0);

    cout << ans;
    return 0;
}