#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> tmp;

void solve(int N) {
    // 중복원소 삭제
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < N; i++) {
        int ans = lower_bound(v.begin(), v.end(), tmp[i]) - v.begin();
        cout << ans << " ";
    }
}

void input(int N) { 
    v.resize(N);
    tmp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> tmp[i];
        v[i] = tmp[i];
    }
    sort(v.begin(), v.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    input(N);
    solve(N);
    return 0;
}