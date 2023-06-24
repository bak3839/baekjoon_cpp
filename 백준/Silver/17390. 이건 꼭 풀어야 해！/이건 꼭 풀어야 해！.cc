#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<int> num;

void Solution() {
    int s, e;

    for (int i = 0; i < Q; i++) {
        cin >> s >> e;
        cout << num[e] - num[s - 1] << "\n";
    }
}

void Input() {
    cin >> N >> Q;

    num.resize(N + 1);
    num[0] = 0;

    for (int i = 1; i <= N; i++) 
        cin >> num[i];

    sort(num.begin(), num.end());

    for (int i = 1; i <= N; i++)
        num[i] += num[i - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();

    return 0;
}