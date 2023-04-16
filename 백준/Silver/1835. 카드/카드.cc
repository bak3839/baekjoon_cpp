#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void Solution(int N) {
    vector<int> ans(N);
    deque<int> q;

    for (int i = 0;i < N;i++)
        q.push_back(i);

    int T, index;
    for (int i = 1;i <= N;i++) {
        T = i;

        while (T--) {
            q.push_back(q.front());
            q.pop_front();
        }
        index = q.front();
        q.pop_front();

        ans[index] = i;
    }

    for (int i = 0;i < N;i++)
        cout << ans[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    Solution(N);

    return 0;
}