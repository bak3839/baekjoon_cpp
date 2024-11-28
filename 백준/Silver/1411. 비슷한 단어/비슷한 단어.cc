#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<char> temp1;
vector<char> temp2;
vector<string> word;

bool CheckWord(string w1, string w2) {
    int index1, index2;

    for (int i = 0; i < w1.size(); i++) {
        index1 = w1[i] - 'a';
        index2 = w2[i] - 'a';

        if (temp1[index1] == '.' && temp2[index2] == '.') {
            temp1[index1] = w2[i];
            temp2[index2] = w1[i];
        }

        else if (temp1[index1] != w2[i] || temp2[index2] != w1[i]) return false;
    }

    return true;
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (CheckWord(word[i], word[j])) ans++;

            fill(temp1.begin(), temp1.end(), '.');
            fill(temp2.begin(), temp2.end(), '.');
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    word.resize(N);
    temp1.resize(26, '.');
    temp2.resize(26, '.');

    for (int i = 0; i < N; i++)
        cin >> word[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}