#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> ans;
vector<int> num;
vector<bool> visit(10001, false);

void Search(int x) {
    if (ans.size() == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = x; i < num.size(); i++) {
        
        ans.push_back(num[i]);
        Search(i);
        ans.pop_back();
    }
}

void Solution() {
    Search(0);
}

void Input() {
    int n;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> n;

        if (!visit[n]) {
            num.push_back(n);
            visit[n] = true;
        }
    }

    sort(num.begin(), num.end());
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}