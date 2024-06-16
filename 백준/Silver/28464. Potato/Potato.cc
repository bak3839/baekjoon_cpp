#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, total;
vector<int> potato;

void Solution(){
    int res = 0;

    for(int i = 0; i < N / 2; i++) {
        res += potato[i];
    }

    cout << res << " " << total - res;
}

void Input() {
    cin >> N;

    potato.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> potato[i];
        total += potato[i];
    }

    sort(potato.begin(), potato.end());
}

void Solve() {
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}