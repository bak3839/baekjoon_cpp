#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int point;
    int country;
    int number;
}Info;

int N;
vector<Info> p;
vector<int> cnt;

bool cmp(Info i1, Info i2) {
    return i1.point > i2.point;
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (ans == 3) break;
        if (cnt[p[i].country] >= 2) continue;

        ans++;
        cnt[p[i].country]++;
        cout << p[i].country << " " << p[i].number << "\n";
    }
}

void Input() {
    cin >> N;

    p.resize(N);
    cnt.resize(N, 0);

    for (int i = 0; i < N; i++) 
        cin >> p[i].country >> p[i].number >> p[i].point;
    sort(p.begin(), p.end(), cmp);
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
