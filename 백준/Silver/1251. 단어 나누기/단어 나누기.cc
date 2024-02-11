#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string word;
vector<string> reverse_word;

string SwapWord(int idx1, int idx2, string tmp) {

    for (int i = 0; i < tmp.size() / 2; i++) {
        char ch = tmp[i];
        tmp[i] = tmp[tmp.size() - i - 1];
        tmp[tmp.size() - i - 1] = ch;
    }  

    return tmp;
}

void Reverse(int idx1, int idx2, string tmp) {
    string res = "";

    res.append(SwapWord(0, idx1, tmp.substr(0, idx1 + 1)));
    res.append(SwapWord(idx1 + 1, idx2, tmp.substr(idx1 + 1, idx2 - idx1)));
    res.append(SwapWord(idx2 + 1, tmp.size() - 1, tmp.substr(idx2 + 1, tmp.size() - idx2 - 1)));

    reverse_word.push_back(res);
}

void Solution() {
    for (int i = 0; i < word.size() - 2; i++) {
        for (int j = i + 1; j < word.size() - 1; j++)
            Reverse(i, j, word);
    }

    sort(reverse_word.begin(), reverse_word.end());
    cout << reverse_word[0];
}

void Input() {
    cin >> word;
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
