#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> num;
vector<int> ans;

void Combination(int x) {
    if (ans.size() == 6) {
        for (int i = 0; i < 6; i++)
            cout << ans[i] << " ";
        cout << "\n";

        return;
    }

    for (int i = x; i < N; i++) {
        ans.push_back(num[i]);
        Combination(i + 1);
        ans.pop_back();
    }
}

void Solution() {
    Combination(0);
    num.clear();
    cout << "\n";
}

void Input() {
    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    

    while (1) {
        cin >> N;

        if (N == 0) break;

        Input();
        Solution();
    }
    return 0;
}