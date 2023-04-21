#include <iostream>
#include <vector>

using namespace std;

int N, ans = 5000;
vector<vector<int>> v;
vector<int> a;
vector<int> b;

void Stats() {
    int idx = 0, asum = 0, bsum = 0, res;
    for (int i = 0; i < N; i++) {
        if (idx < N / 2 && a[idx] == i) idx++;
        else b.push_back(i);
    }

    for (int i = 0; i < (N / 2) - 1; i++) {
        for (int j = i + 1; j < (N / 2); j++) {
            asum += v[a[i]][a[j]];
            asum += v[a[j]][a[i]];
            bsum += v[b[i]][b[j]];
            bsum += v[b[j]][b[i]];
        }
    }
    b.clear();

    if (asum >= bsum) res = asum - bsum;
    else res = bsum - asum;
    ans = ans > res ? res : ans;
}


void Solution(int s) {
    if (a.size() == N / 2) {
        Stats();
        return;
    }

    for (int i = s; i < N; i++) {
        a.push_back(i);
        Solution(i + 1);
        a.pop_back();
    }
}

void Input() {
    cin >> N;
    v.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> v[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution(0);
    cout << ans;
    return 0;
}