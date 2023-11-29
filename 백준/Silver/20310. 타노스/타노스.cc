#include <iostream>
#include <deque>

using namespace std;

string str;
deque<int> one;
deque<int> zero;

void Solution() {
    string ans = "";
    int sizeO = one.size(), sizeZ = zero.size();

    for (int i = 0; i < sizeO / 2; i++)
        one.pop_front();

    for (int i = 0; i < sizeZ / 2; i++)
        zero.pop_back();

    for (int i = 0; i < str.size(); i++) {
        if (!one.empty() && one.front() == i) {
            ans.push_back('1');
            one.pop_front();
        }

        else if (!zero.empty() && zero.front() == i) {
            ans.push_back('0');
            zero.pop_front();
        }
    }

    cout << ans;
}

void Input() {
    cin >> str;

    for (int i = 0;i < str.size(); i++) {
        if (str[i] == '1') one.push_back(i);
        else zero.push_back(i);
    }
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
