#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> tree;

void Solution() {
    int day = 1, ans = 0;

    for (int i = 0; i < N; i++)
        ans = max(ans, tree[i] + day++ + 1);

    cout << ans;
}

void Input() {
    cin >> N;

    tree.resize(N);

    for (int i = 0; i < N; i++)
        cin >> tree[i];
    sort(tree.begin(), tree.end(), greater<int>());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
