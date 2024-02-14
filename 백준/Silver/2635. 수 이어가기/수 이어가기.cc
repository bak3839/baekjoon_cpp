#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int> num;
vector<int> ansNum;

void Search(int cnt) {
    int res = num[num.size() - 2] - num[num.size() - 1];

    if (res < 0) {
        if (ans < cnt) {
            ans = cnt;
            ansNum.clear();
            ansNum.insert(ansNum.begin(), num.begin(), num.end());
        }
        return;
    }

    num.push_back(res);
    Search(cnt + 1);
    num.pop_back();
}

void Solution() {
    for (int i = n; i >= 0; i--) {
        num.push_back(i);
        Search(2);
        num.pop_back();
    }

    cout << ans << "\n";
    for (int i = 0; i < ansNum.size(); i++)
        cout << ansNum[i] << " ";
}

void Input() { 
    cin >> n;
    num.push_back(n);
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
