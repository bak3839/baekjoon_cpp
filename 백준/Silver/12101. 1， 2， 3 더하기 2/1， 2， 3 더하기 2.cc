#include <iostream>
#include <vector>

using namespace std;

bool finish;
int N, K, cnt;
vector<int> num;

void Search(int sum) {
    if (finish || sum > N) return;

    if (sum == N) {
        cnt++;
        if (cnt == K) {
            finish = true;

            for (int i = 0; i < num.size() - 1; i++)
                cout << num[i] << "+";
            cout << num.back();
        }
    }

    for (int i = 1; i <= 3; i++) {
        num.push_back(i);
        Search(sum + i);
        num.pop_back();
    }
}

void Solution() {
    Search(0);

    if (!finish) cout << -1;
}

void Input() {
    cin >> N >> K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}