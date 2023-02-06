#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, S;
vector<int> num;

int search() {
    int ans = 0;
    queue<pair<int, int>> q;   
    q.push({ 0, 1 });

    while(!q.empty()) {
        int now = q.front().first;
        int idx = q.front().second;
        q.pop();

        if (idx > N) continue;

        if (now + num[idx] == S) ++ans;

        q.push({ now, idx + 1 });
        q.push({ now + num[idx], idx + 1 });
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> S;
    num.resize(N + 1);
    num[0] = 0;

    for (int i = 1; i <= N; i++) cin >> num[i];

    cout << search();
    return 0;
}