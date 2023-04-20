#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

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

    for (int i = 1; i <= N; i++) {
        ans.push_back(i);
        Solution(N, M, i + 1);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    Solution(N, M, 1);
    return 0;
}