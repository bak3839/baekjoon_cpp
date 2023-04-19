#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
vector<bool> check;

void Print(int M) {
    for (int i = 0; i < M; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

void Solution(int N, int M, int s) {
    if (ans.size() == M) {
        Print(M);
        return;
    }

    for (int i = s; i <= N; i++) {
        if (check[i]) continue;

        check[i] = true;
        ans.push_back(i);
        Solution(N, M, i + 1);
        check[i] = false;
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    check.resize(N + 1, false);
    Solution(N, M, 1);
    return 0;
}