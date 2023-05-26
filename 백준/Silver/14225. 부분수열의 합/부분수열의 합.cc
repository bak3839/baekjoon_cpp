#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> s;
vector<int> tmp;
vector<bool> check;

void Search(int sum, int index, int cnt, int len) {
    if (cnt == len) {
        check[sum] = true;
        return;
    }

    for (int i = index; i < N; i++) {
        cnt++;
        Search(sum + s[i], i + 1, cnt, len);
        cnt--;
    }
}

void Solution() {
    for (int i = 2; i < N; i++) {
        Search(0, 0, 0, i);
    }

    for (int i = 1; i <= check.size(); i++) {
        if (check[i]) continue;
        cout << i;
        break;
    }
}

void Input() {
    int sum = 0;
    cin >> N;
    s.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> s[i];
        sum += s[i];
    }

    check.resize(sum + 2, false);

    for (int i = 0; i < N; i++) check[s[i]] = true;
    check[sum] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}