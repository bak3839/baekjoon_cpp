#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> num;

void Solution() {
    sort(num.begin(), num.end());

    for (int i = 0; i < N; i++)
        cout << num[i] << "\n";
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}