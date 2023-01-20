#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int N;
vector<int> v;

int change(int x) {
    vector<int> tmp;
    int cnt = 0, res = 0;

    for (int i = 0; i < N; i++) {
        if (x == v[i]) tmp.push_back(-1);
        else tmp.push_back(1);
    }

    for (int i = 0; i < N; i++) {
        cnt += tmp[i];
        cnt = max(0, cnt);
        res = max(cnt, res);
    }

    tmp.clear();
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++) cin >> v[i];

    cout << max(change(1), change(2));
    return 0;
}