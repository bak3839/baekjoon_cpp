#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int R, C, K;
int A[101][101];

bool compare(const pii &p1, const pii &p2) {
    if (p1.second == p2.second) 
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int Row(int r, int c) {
    int cCnt = c;
    map<int, int> m;
    vector<int> idx;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (A[i][j] == 0) continue;

            m[A[i][j]]++;
        }

        vector<pii> res(m.begin(), m.end());
        sort(res.begin(), res.end(), compare);

        for (int j = 0; j < res.size() && j < 50; j++) {
            A[i][2 * j + 1] = res[j].first;
            A[i][2 * j + 2] = res[j].second;
        }

        int cnt = (res.size() * 2 > 100 ? 100 : res.size() * 2);
        idx.push_back(cnt);
        cCnt = max(cCnt, cnt);
        
        m.clear();
    }

    for (int i = 1; i <= r; i++) {
        for (int j = idx[i - 1] + 1; j <= cCnt; j++) A[i][j] = 0;
    }

    return cCnt;
}

int Col(int r, int c) {
    int rCnt = r;
    map<int, int> m;
    vector<int> idx;

    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            if (A[j][i] == 0) continue;

            m[A[j][i]]++;
        }

        vector<pii> res(m.begin(), m.end());
        sort(res.begin(), res.end(), compare);

        for (int j = 0; j < res.size() && j < 50; j++) {
            A[2 * j + 1][i] = res[j].first;
            A[2 * j + 2][i] = res[j].second;
        }

        int cnt = (res.size() * 2 > 100 ? 100 : res.size() * 2);
        idx.push_back(cnt);
        rCnt = max(rCnt, cnt);

        m.clear();
    }

    for (int i = 1; i <= c; i++) {
        for (int j = idx[i - 1] + 1; j <= rCnt; j++) A[j][i] = 0;
    }

    return rCnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rCnt = 3, cCnt = 3, T = 0;
    cin >> R >> C >> K;
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> A[i][j];
        }
    }

    while (T <= 100) {
        if (A[R][C] == K) break;

        if (rCnt >= cCnt) cCnt = Row(rCnt, cCnt);
        else rCnt = Col(rCnt, cCnt);

        T++;
    }

    if (T > 100) cout << -1;
    else cout << T;

    return 0;
}