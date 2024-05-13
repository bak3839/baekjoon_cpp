#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string word;
vector<string> ans;
int parse[2];

string ReverseWord(string s) {
    string res = "";

    for (int i = s.size() - 1; i >= 0; i--) {
        res.push_back(s[i]);
    }

    return res;
}

string SubString(int s, int e) {
    string res = "";

    for (int i = s; i < e; i++) {
        res.push_back(word[i]);
    }

    return res;
}

void MakeWord() {
    int prev = 0;
    string res = "";

    for (int i = 0; i < 2; i++) {
        res.append(ReverseWord(SubString(prev, parse[i])));
        prev = parse[i];
    }
    res.append(ReverseWord(SubString(prev, word.size())));

    ans.push_back(res);
}

void ParsingWord(int idx, int x) {
    if (idx == 2) {
        MakeWord();
        return;
    }

    for (int i = x; i < word.size(); i++) {
        parse[idx] = i;
        ParsingWord(idx + 1, i + 1);
    }
}

void Solution() {
    ParsingWord(0, 1);
    sort(ans.begin(), ans.end());

    cout << ans[0];
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