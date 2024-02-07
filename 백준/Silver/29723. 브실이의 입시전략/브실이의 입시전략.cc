#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using psi = pair<string, int>;

int N, M, K, sum;
map<string, int> m;

bool cmp(psi p1, psi p2) {
    return p1.second > p2.second;
}

void Solution() {
    int maxNum = sum, minNum = sum;

    vector<psi> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < M - K; i++) {
        maxNum += v[i].second;
        minNum += v[v.size() - i - 1].second;
    }

    cout << minNum << " " << maxNum;
}

void Input() {
    int point;
    string subject;
    map<string, int>::iterator iter;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> subject >> point;
        m[subject] = point;
    }

    for (int i = 0; i < K; i++) {
        cin >> subject;
       
        sum += m[subject];
        iter = m.find(subject);
        m.erase(iter);
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
