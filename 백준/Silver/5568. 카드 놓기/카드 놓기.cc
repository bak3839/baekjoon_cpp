#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K, ans;
vector<string> num;
vector<string> now;

vector<bool> use;
vector<bool> check;


void Search(int cnt) {
    if (cnt == K) {
        string res = "";

        for (int i = 0;i < K; i++) 
            res.append(now[i]);

        if (!check[stoi(res)]) {
            ans++;
            check[stoi(res)] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        if (use[i]) continue;

        use[i] = true;
        now.push_back(num[i]);

        Search(cnt + 1);

        use[i] = false;
        now.pop_back();
    }
}

void Solution() {
    Search(0);
    cout << ans;
}

void Input() {
    cin >> N >> K;

    num.resize(N);
    use.resize(N, false);
    check.resize(100000000, false);

    for (int i = 0;i < N; i++)
        cin >> num[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}