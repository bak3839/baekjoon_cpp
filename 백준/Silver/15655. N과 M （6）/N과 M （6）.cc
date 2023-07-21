#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<bool> check;
vector<int> num;
vector<int> S;

void Sequence(int x) {
    if (S.size() == M) {
        for (int i = 0; i < M; i++)
            cout << S[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = x; i < N; i++) {
        if (check[i]) continue;

        S.push_back(num[i]);
        check[i] = true;

        Sequence(i + 1);

        S.pop_back();
        check[i] = false;
    }
}

void Solution() {
    Sequence(0);
}

void Input() {
    cin >> N >> M;

    num.resize(N);
    check.resize(N, false);

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