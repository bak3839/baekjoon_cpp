#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> ans;

void Solution(int N) {
    for (int i = 0; i < N; i++) {
        int loc = v[i], cnt = 0;

        for (int j = 0; j < N; j++) {
            if (ans[j] != 0) continue;
            if (cnt == loc) {
                ans[j] = i + 1;
                break;
            }
            cnt++;
        }
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}

void Input(int N) {
    v.resize(N);
    ans.resize(N, 0);
    for (int i = 0; i < N; i++)
        cin >> v[i];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    Input(N);
    Solution(N);
    return 0;
}