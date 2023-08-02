#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> num;
vector<int> S;

void Sequence() {
    if (S.size() == M) {
        for (int i = 0; i < M; i++)
            cout << S[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        S.push_back(num[i]);
        Sequence();
        S.pop_back();
    }
}

void Solution() {
    Sequence();
}

void Input() {
    cin >> N >> M;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}