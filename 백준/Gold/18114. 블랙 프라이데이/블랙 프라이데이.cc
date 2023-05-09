#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C, limit, ans;
vector<int> w;
vector<int> visit;

void Check(int sum) {
    int index = lower_bound(w.begin(), w.end(), C - sum) - w.begin();

    if (index >= N) return;

    for (int i = 0; i < limit; i++) {
        if (visit[i] == index) return;
    }

    if (w[index] + sum == C) ans = 1;
}

void Combination(int x, int sum, int cnt) {
    if (ans) return;

    if (limit == cnt) {
        Check(sum);
        return;
    }

    for (int i = x; i < N; i++) {
        if (sum + w[i] > C) break;

        visit.push_back(i);      
        Combination(i + 1, sum + w[i], cnt + 1);
        visit.pop_back();
    }   
}

void Solution() {
    for (int i = 0; i <= 2; i++) { 
        limit = i;
        Combination(0, 0, 0);

        if (ans) break;
    }

    cout << ans;
}

void Input() {
    cin >> N >> C;
    w.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
       
    sort(w.begin(), w.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}